/*
 * \brief  Implementation of the SIGNAL interface
 * \author Norman Feske
 * \author Stefan Kalkowski
 * \date   2009-08-11
 */

/*
 * Copyright (C) 2009-2013 Genode Labs GmbH
 *
 * This file is part of the Genode OS framework, which is distributed
 * under the terms of the GNU General Public License version 2.
 */

/* Genode includes */
#include <base/log.h>
#include <base/native_capability.h>

/* core includes */
#include <platform.h>
#include <signal_source_component.h>
#include <cpu_thread_component.h> // lj

namespace Fiasco {
#include <l4/sys/factory.h>
#include <l4/sys/irq.h>
}

using namespace Genode;


/*****************************
 ** Signal-source component **
 *****************************/

void Signal_source_component::release(Signal_context_component *context)
{
	if (context && context->enqueued())
		_signal_queue.remove(context);
}

void Signal_source_component::submit(Signal_context_component *context,
                                     unsigned long             cnt)
{
	/* enqueue signal to context */
	context->increment_signal_cnt(cnt);

	if (!context->enqueued()) {
		_signal_queue.enqueue(context);

		/* wake up client */
		Fiasco::l4_irq_trigger(_blocking_semaphore.data()->kcap());
	}
}


Signal_source::Signal Signal_source_component::wait_for_signal()
{
	if (_signal_queue.empty()) {
		warning("unexpected call of wait_for_signal");
		return Signal(0, 0);
	}

	/* dequeue and return pending signal */
	Signal_context_component *context = _signal_queue.dequeue();
	Signal result(context->imprint(), context->cnt());
	context->reset_signal_cnt();
	return result;
}


Signal_source_component::Signal_source_component(Rpc_entrypoint *ep)
:
	Signal_source_rpc_object(*cap_map()->insert(platform_specific()->cap_id_alloc()->alloc()), ep),
	_entrypoint(ep), _finalizer(*this),
	_finalizer_cap(_entrypoint->manage(&_finalizer))
{
	using namespace Fiasco;

	log("[cap_cr][core][Signal_source_component::ctor] Creating semaphore IRQ id: ", Hex(_blocking_semaphore.data()->id()) ," kcap: ", Hex(_blocking_semaphore.data()->kcap()), "...");
	raw("cap_cr|STAGE|signal_semaphore_irq|");

	l4_msgtag_t res = l4_factory_create_irq(L4_BASE_FACTORY_CAP,
	                                        _blocking_semaphore.data()->kcap());
	if (l4_error(res))
		error("Allocation of irq object failed!");
	else
		raw("cap_cr|l4_factory_create_irq|", Hex(_blocking_semaphore.data()->id()), "|");
}


Signal_source_component::~Signal_source_component()
{
	_finalizer_cap.call<Finalizer::Rpc_exit>();
	_entrypoint->dissolve(&_finalizer);
}


void Signal_source_component::Finalizer_component::exit()
{
	/*
	 * On Fiasco.OC, the signal-source client does not use a blocking call
	 * to wait for signals. Hence, we do not need to take care of
	 * releasing the reply capability of such a call.
	 */
}

#include <cpu_thread/client.h>

// lj
void Signal_source_rpc_object::_attach_semaphore(Thread_capability thread_cap)//int thread_obj_id)
{
/*	using namespace Fiasco;

//	log("[cap_cr][Signal_source_rpc_object::_attach_semaphore] thread_cap id: ", Hex(thread_cap.local_name()), ", kcap: ", Hex(thread_cap.data()->kcap()));

//	Genode::Cpu_thread_client ctc(thread_cap);
//	auto state = ctc.state();
//	log("[cap_cr][Signal_source_rpc_object::_attach_semaphore] thread state id: ", Hex(state.id), ", kcap: ", Hex(state.kcap));

//	log("[cap_cr][Signal_source_rpc_object::_attach_semaphore] thread_obj_id = ", Hex(thread_obj_id), ", Rpc_entrypoint = ", Hex((addr_t)_ep));

//	l4_irq_detach(_blocking_semaphore.data()->kcap());

	_ep->apply(thread_cap, [&] (Cpu_thread_component *t) {

	//	auto sem_id = _blocking_semaphore.data()->id();
	//	auto sem_kcap = _blocking_semaphore.data()->kcap();

	//	log("[cap_cr][Signal_source_rpc_object::_attach_semaphore] sem id: ", Hex(sem_id), " kcap: ", Hex(sem_kcap));

		if (t)
		{

		//	auto thread_id = t->platform_thread().thread().local.data()->id();
		//	auto thread_kcap = t->platform_thread().thread().local.data()->kcap();
		//	auto thread_state = t->state();
		//	auto& gate = t->platform_thread().gate();

		//	log("[cap_cr][Signal_source_rpc_object::_attach_semaphore] thread id: ", Hex(thread_id), " kcap: ", Hex(thread_kcap));
		//	log("[cap_cr][Signal_source_rpc_object::_attach_semaphore] thread state id: ", Hex(gate.local.data()->id()), ", kcap: ", Hex(gate.local.data()->kcap()));

		//	l4_msgtag_t tag = l4_irq_attach(_blocking_semaphore.data()->kcap(), 0,
		//			gate.local.data()->kcap());
		//	if (l4_error(tag))
		//			Genode::raw("l4_irq_attach failed with ", l4_error(tag));
		}
		else
		//	log("[cap_cr][Signal_source_rpc_object::_attach_semaphore] Cpu_thread_component* is nullptr");
			;
	  }
	);
*/
}
