/* $clens$ */
/*
 * Copyright (c) 2010 Conformal Systems LLC <info@conformal.com>
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

/*
 * This file contains ifdefs and #defines to bring the OS into focus
 * so that the source can build on any supported platform.
 */

#ifdef __FreeBSD__
#define SA_LEN(x)      ((x)->sa_len)
#define __dead __dead2

#include <string.h>
#define NEED_ARC4RANDOM_BUF
#define NEED_STRNVIS
#endif /* __FreeBSD__ */

#ifdef __linux__
#define SA_LEN(x)      sizeof(struct sockaddr)
#define __dead 

#include <stdlib.h>
#define NO_UTIL_H

#define NEED_ARC4RANDOM_BUF
#define NEED_STRNVIS
#define NEED_STRLCAT
#define NEED_STRLCPY
#define NEED_FMT_SCALED
#endif /* __linux__ */

#ifdef NEED_ARC4RANDOM_BUF
void arc4random_buf(void *buf, size_t nbytes);
#endif /* NEED_ARC4RANDOM_BUF */

#ifdef NEED_STRNVIS
int strnvis(char *dst, const char *src, size_t siz, int flag);
#endif /* NEED_STRNVIS */

#ifdef NEED_STRLCAT
size_t strlcat(char *, const char *, size_t);
#endif /* NEED_STRLCAT */

#ifdef NEED_STRLCPY
size_t strlcpy(char *, const char *, size_t);
#endif /* NEED_STRLCPY */

#ifdef NEED_FMT_SCALED
#define	FMT_SCALED_STRSIZE	7	/* minus sign, 4 digits, suffix, null byte */

int fmt_scaled(long long number, char *result);
#endif /* NEED_FMT_SCALED */
