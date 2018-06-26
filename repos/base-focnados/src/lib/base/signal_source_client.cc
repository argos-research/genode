/*
 * \brief  Fiasco.OC-specific signal-source client interface
 * \author Norman Feske
 * \author Stefan Kalkowski
 * \date   2010-02-03
 */

/*
 * Copyright (C) 2011-2013 Genode Labs GmbH
 *
 * This file is part of the Genode OS framework, which is distributed
 * under the terms of the GNU General Public License version 2.
 */

/* Genode includes */
#include <signal_source/client.h>
#include <base/thread.h>
#include <base/log.h>
#include <base/printf.h> // lj

/* base-internal includes */
#include <base/internal/capability_data.h>
#include <base/internal/native_thread.h>

/* Fiasco includes */
namespace Fiasco {
#include <l4/sys/irq.h>
#include <l4/sys/kdebug.h> // lj
}

using namespace Genode;


Signal_source_client::Signal_source_client(Capability<Signal_source> cap)
:
	Rpc_client<Foc_signal_source>(static_cap_cast<Foc_signal_source>(cap))
{
	using namespace Fiasco;

	/* request mapping of semaphore capability selector */
	PLOG("[lj][Signal_source_client::ctor] Requesting semaphore via RPC...");
//	enter_kdebug("Before semaphore request");
	_sem = call<Rpc_request_semaphore>();
//	enter_kdebug("After semaphore request");

	PLOG("[lj][Signal_source_client::ctor] Attaching IRQ to thread...");

	log("[lj][Signal_source_client::ctor] semaphore IRQ id: ", Hex(_sem.data()->id()) ," kcap: ", Hex(_sem.data()->kcap()), " thread: ", Hex(Thread::myself()->native_thread().kcap));
	l4_msgtag_t tag = l4_irq_attach(_sem.data()->kcap(), 0,
	 Thread::myself()->native_thread().kcap);
	if (l4_error(tag))
		Genode::raw("l4_irq_attach failed with ", l4_error(tag));
	else
	{
		Genode::raw("cap_cr|l4_irq_attach|", Hex(_sem.data()->id()), "|", Hex(Thread::myself()->cap().data()->id() ), "|");
		Genode::raw("cap_cr|semaphore_irq|", Hex(_sem.data()->id()), "|", Hex(Thread::myself()->cap().data()->id() ), "|");
	}
}

// lj
Signal_source_client::Signal_source_client(Capability<Signal_source> cap, Thread_capability thread_cap)//int thread_obj_id)
:
	Rpc_client<Foc_signal_source>(static_cap_cast<Foc_signal_source>(cap))
{
//	_sem = call<Rpc_request_semaphore>();
	restored = true;
//	call<Rpc_attach_semaphore>(thread_cap);//thread_obj_id);
}

Signal_source_client::~Signal_source_client()
{
	Genode::log("[lj] before detach");

	if(!restored)
		Fiasco::l4_msgtag_t tag = Fiasco::l4_irq_detach(_sem.data()->kcap());

	Genode::raw("cap_cr|l4_irq_detach|", Hex(_sem.data()->id()));
}


__attribute__((optimize("-fno-omit-frame-pointer")))
__attribute__((noinline))
Signal_source_client::Signal Signal_source_client::wait_for_signal()
{
	using namespace Fiasco;

	Signal signal;
	do {

		/* block on semaphore until signal context was submitted */
		l4_irq_receive(_sem.data()->kcap(), L4_IPC_NEVER);

		/*
		 * The following request will return immediately and either
		 * return a valid or a null signal. The latter may happen in
		 * the case a submitted signal context was destroyed (by the
		 * submitter) before we have a chance to raise our request.
		 */
		signal = call<Rpc_wait_for_signal>();

	} while (!signal.imprint());

	return signal;
}
