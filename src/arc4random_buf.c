/*
 * Copyright (c) 2011 Conformal Systems LLC <info@conformal.com>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <clens.h>

#ifdef NEED_ARC4RANDOM_BUF

#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>

#if defined(__linux__) || defined(__CYGWIN__)
#include <bsd/stdlib.h>
#endif

void
arc4random_buf(void *buf, size_t nbytes)
{
	uint32_t		data;
	uint8_t			data8;
	uint8_t			*buf8 = buf;

	while (nbytes > 0) {
		data = arc4random();
		switch(nbytes) {
		default:
			/* fallthru */
		case 4:
			data8 = data & 0xff;
			data = data >> 8;
			*buf8++ = data8;
			/* fallthru */
		case 3:
			data8 = data & 0xff;
			data = data >> 8;
			*buf8++ = data8;
			/* fallthru */
		case 2:
			data8 = data & 0xff;
			data = data >> 8;
			*buf8++ = data8;
			/* fallthru */
		case 1:
			data8 = data & 0xff;
			*buf8++ = data8;
			break;
		}
		nbytes -= 4;
	}
}
#endif /* NEED_ARC4RANDOM_BUF */

