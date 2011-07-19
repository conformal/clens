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

#ifndef CLENS_H
#define CLENS_H

/* versioning */
#define CLENS_VERSION_MAJOR	0
#define CLENS_VERSION_MINOR	0
#define CLENS_VERSION_PATCH	5
#define CLENS_VERSION		"0.0.5"

void	clens_version(int *major, int *minor, int *patch);

#include <sys/time.h>

#ifdef __FreeBSD__
#define SA_LEN(x)      ((x)->sa_len)
#define __dead __dead2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NO_UTIL_H

#define NEED_ARC4RANDOM_BUF
#define NEED_STRNVIS
#define NEED_FMT_SCALED
#define NEED_FGETLN
#define NEED_FPARSELN
#endif /* __FreeBSD__ */

#ifdef __linux__
#define SA_LEN(x)	sizeof(struct sockaddr)
#define __dead 
#define __packed	__attribute__((__packed__))
#ifndef PASS_MAX
#define PASS_MAX	1024
#endif /* PASS_MAX */

#include <stdio.h>
#include <stdlib.h>
#define NO_UTIL_H

#define NEED_ARC4RANDOM_BUF
#define NEED_STRNVIS
#define NEED_STRLCAT
#define NEED_STRLCPY
#define NEED_FMT_SCALED
#define NEED_FGETLN
#define NEED_FPARSELN

#endif /* __linux__ */

#ifndef timespeccmp
#define	timespeccmp(tsp, usp, cmp)					\
	(((tsp)->tv_sec == (usp)->tv_sec) ?				\
	    ((tsp)->tv_nsec cmp (usp)->tv_nsec) :			\
	    ((tsp)->tv_sec cmp (usp)->tv_sec))
#endif

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
int scan_scaled(char *scaled, long long *result);
#endif /* NEED_FMT_SCALED */

#ifdef NEED_FGETLN
char *fgetln(FILE *, size_t *);
#endif /* NEED_FGETLN */

#ifdef NEED_FPARSELN
char *fparseln(FILE *, size_t *, size_t *, const char [3], int);
#endif /* NEED_FPARSELN */

#endif /* CLENS_H */
