/*
 * \brief  Test for exercising the seL4 kernel interface
 * \author Norman Feske
 * \date   2014-10-14
 */

/*
 * Copyright (C) 2014 Genode Labs GmbH
 *
 * This file is part of the Genode OS framework, which is distributed
 * under the terms of the GNU General Public License version 2.
 */

/* Genode includes */
#include <base/printf.h>

int main()
{
	PDBG("a message printed via Genode's PDBG");

	*(int *)0x1122 = 0;
	return 0;
}