/*
 * \brief  Audio library interface
 * \author Josef Soentgen
 * \date   2014-12-27
 *
 * This header declares the private Audio namespace. It contains
 * functions called by the driver frontend that are implemented
 * by the driver library.
 */

/*
 * Copyright (C) 2014 Genode Labs GmbH
 *
 * This file is part of the Genode OS framework, which is distributed
 * under the terms of the GNU General Public License version 2.
 */

#ifndef _AUDIO__AUDIO_H_
#define _AUDIO__AUDIO_H_

#include <os/server.h>

/*****************************
 ** private Audio namespace **
 *****************************/

namespace Audio_out {

	enum Channel_number { LEFT, RIGHT, MAX_CHANNELS, INVALID = MAX_CHANNELS };
}


namespace Audio_in {

	enum Channel_number { LEFT, MAX_CHANNELS, INVALID = MAX_CHANNELS };
}


namespace Audio {

	void init_driver(Server::Entrypoint &ep);

	bool driver_active();

	void play_sigh(Genode::Signal_context_capability cap);

	void record_sigh(Genode::Signal_context_capability cap);

	int play(short *data, Genode::size_t size);

	int record(short *data, Genode::size_t size);
}

#endif /* _AUDIO__AUDIO_H_ */
