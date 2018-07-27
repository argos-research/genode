/*
 * \brief  Signal-source server interface
 * \author Norman Feske
 * \date   2010-02-03
 */

/*
 * Copyright (C) 2010-2013 Genode Labs GmbH
 *
 * This file is part of the Genode OS framework, which is distributed
 * under the terms of the GNU General Public License version 2.
 */

#ifndef _INCLUDE__SIGNAL_SOURCE__RPC_OBJECT_H_
#define _INCLUDE__SIGNAL_SOURCE__RPC_OBJECT_H_

#include <base/rpc_server.h>
#include <signal_source/foc_signal_source.h>

namespace Genode { struct Signal_source_rpc_object; }


struct Genode::Signal_source_rpc_object : Rpc_object<Foc_signal_source,
                                                     Signal_source_rpc_object>
{
	protected:

		Native_capability _blocking_semaphore;

	private:

		Rpc_entrypoint* _ep;

	public:

		Signal_source_rpc_object(Native_capability cap, Rpc_entrypoint* ep)
		: _blocking_semaphore(cap)
		, _ep(ep)
		{
			log("[cap_cr][Signal_source_rpc_object::ctor]");
		}

		Native_capability _request_semaphore()
		{
			log("[cap_cr][Signal_source_rpc_object::_request_semaphore]");
			return _blocking_semaphore;
		}

		void _attach_semaphore(Thread_capability thread_cap);//int thread_obj_id); // implementation in signal_source_component.cc
};

#endif /* _INCLUDE__SIGNAL_SOURCE__RPC_OBJECT_H_ */
