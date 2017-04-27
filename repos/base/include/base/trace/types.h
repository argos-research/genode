/*
 * \brief  Basic types used by the tracing infrastructure
 * \author Norman Feske
 * \date   2013-08-12
 */

#ifndef _INCLUDE__BASE__TRACE__TYPES_H_
#define _INCLUDE__BASE__TRACE__TYPES_H_

/* Genode includes */
#include <util/string.h>
#include <base/affinity.h>

namespace Genode { namespace Trace {

	/*********************
	 ** Exception types **
	 *********************/

	struct Policy_too_large        : Exception { };
	struct Out_of_metadata         : Exception { };
	struct Nonexistent_subject     : Exception { };
	struct Already_traced          : Exception { };
	struct Source_is_dead          : Exception { };
	struct Nonexistent_policy      : Exception { };
	struct Traced_by_other_session : Exception { };
	struct Subject_not_traced      : Exception { };

	typedef String<160> Session_label;
	typedef String<32>  Thread_name;

	struct Policy_id;
	struct Subject_id;
	struct Execution_time;
	struct CPU_info;
	struct RAM_info;
	struct SCHEDULER_info;
} }


/**
 * Session-local policy identifier
 */
struct Genode::Trace::Policy_id
{
	unsigned id;

	Policy_id() : id(0) { }
	Policy_id(unsigned id) : id(id) { }

	bool operator == (Policy_id const &other) const { return id == other.id; }
};


/**
 * Session-local trace-subject identifier
 */
struct Genode::Trace::Subject_id
{
	unsigned id;

	Subject_id() : id(0) { }
	Subject_id(unsigned id) : id(id) { }

	bool operator == (Subject_id const &other) const { return id == other.id; }
};


/**
 * Execution time of trace subject
 *
 * The value is kernel specific.
 */
struct Genode::Trace::Execution_time
{
	unsigned long long value;

	Execution_time() : value(0) { }
	Execution_time(unsigned long long value) : value(value) { }
};


/**
 * Subject information
 */
class Genode::Trace::CPU_info
{
	public:

		enum State { INVALID, UNTRACED, TRACED, FOREIGN, ERROR, DEAD };

		static char const *state_name(State state)
		{
			switch (state) {
			case INVALID:  return "INVALID";
			case UNTRACED: return "UNTRACED";
			case TRACED:   return "TRACED";
			case FOREIGN:  return "FOREIGN";
			case ERROR:    return "ERROR";
			case DEAD:     return "DEAD";
			}
			return "INVALID";
		}

	private:

		Session_label      _session_label;
		Thread_name        _thread_name;
		State              _state;
		Policy_id          _policy_id;
		Execution_time     _execution_time;
		Affinity::Location _affinity;
		unsigned	   _prio;
		unsigned	   _id;


	public:

		CPU_info() : _state(INVALID) { }

		CPU_info(Session_label const &session_label,
		             Thread_name   const &thread_name,
		             State state, Policy_id policy_id,
		             Execution_time execution_time,
		             Affinity::Location affinity,
			     unsigned prio,
			     unsigned id
				)
		:
			_session_label(session_label), _thread_name(thread_name),
			_state(state), _policy_id(policy_id),
			_execution_time(execution_time), _affinity(affinity), _prio(prio), _id(id)
		{ }

		Session_label const &session_label()  const { return _session_label; }
		Thread_name   const &thread_name()    const { return _thread_name; }
		State                state()          const { return _state; }
		Policy_id            policy_id()      const { return _policy_id; }
		Execution_time       execution_time() const { return _execution_time; }
		Affinity::Location   affinity()       const { return _affinity; }
		unsigned	     prio()	      const { return _prio; }
		unsigned	     id()	      const { return _id; }

};

class Genode::Trace::RAM_info
{
	private:

		Session_label      _session_label;
		Thread_name        _thread_name;
		size_t		   _ram_quota;
		size_t		   _ram_used;

	public:

		RAM_info() {}

		RAM_info(Session_label const &session_label,
		             Thread_name   const &thread_name,
			     size_t ram_quota,
			     size_t ram_used
				)
		:
			_session_label(session_label), _thread_name(thread_name),
			_ram_quota(ram_quota), _ram_used(ram_used)
		{ }

		Session_label const &session_label()  const { return _session_label; }
		Thread_name   const &thread_name()    const { return _thread_name; }
		size_t		     ram_quota()      const { return _ram_quota; }
		size_t		     ram_used()	      const { return _ram_used; }
};

class Genode::Trace::SCHEDULER_info
{
	private:

		Execution_time	_idle;
		bool		_core0_is_online;
		bool		_core1_is_online;
		bool		_core2_is_online;
		bool		_core3_is_online;
		unsigned	_num_cores;
		long unsigned int	   _foc_id;

	public:

		SCHEDULER_info() {}

		SCHEDULER_info(Execution_time idle,
				bool core0_is_online,
				bool core1_is_online,
				bool core2_is_online,
				bool core3_is_online,
				unsigned num_cores,
			    	long unsigned int foc_id)
		:
			_idle(idle), _core0_is_online(core0_is_online), _core1_is_online(core1_is_online),
			_core2_is_online(core2_is_online), _core3_is_online(core3_is_online),
			_num_cores(num_cores), _foc_id(foc_id)
		{}

		Execution_time		idle()			const { return _idle; }
		bool			core0_is_online()	const { return _core0_is_online; }
		bool			core1_is_online()	const { return _core1_is_online; }
		bool			core2_is_online()	const { return _core2_is_online; }
		bool			core3_is_online()	const { return _core3_is_online; }
		unsigned		num_cores()		const { return _num_cores; }
		long unsigned int	     foc_id()	      const { return _foc_id; }
};

#endif /* _INCLUDE__BASE__TRACE__TYPES_H_ */
