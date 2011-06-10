# $clens$


LIB= clens
SRCS+= clens.c arc4random_buf.c strnvis.c 
HDRS+= clens/clens.h
HDRDIRS+= clens

SYSTEM != uname -s
.if exists(${.CURDIR}/config/Makefile.$(SYSTEM:L))
.include "${.CURDIR}/config/Makefile.$(SYSTEM:L)"
.endif

LOCALBASE?=/usr/local
BINDIR?=${LOCALBASE}/bin
LIBDIR?=${LOCALBASE}/lib
INCDIR?=${LOCALBASE}/include

.PATH: $(.CURDIR)/src

CFLAGS+= -Wall -Werror
CFLAGS+= -ggdb3 -I${.CURDIR}/include/clens -I${INCDIR}

afterinstall:
	@for d in $(HDRDIRS); do \
	echo "$(INSTALL) -d -m 0755 $(INCDIR)/$$d"; \
	${INSTALL} -d -m 0755 ${INCDIR}/$$d; \
	done
	@cd ${.CURDIR}/include; for i in ${HDRS}; do \
	cmp -s $$i ${INCDIR}/$$i || \
	${INSTALL} ${INSTALL_COPY} -m 444 -o $(BINOWN) -g $(BINGRP) $$i ${INCDIR}/$$i; \
	echo ${INSTALL} ${INSTALL_COPY} -m 444 -o $(BINOWN) -g $(BINGRP) $$i ${INCDIR}/$$i; \
	done

uninstall:
	@for i in $(HDRS); do \
	echo rm -f ${INCDIR}/$$i ;\
	rm -f ${INCDIR}/$$i; \
	done
	@for i in $(_LIBS); do \
	echo rm -f ${LIBDIR}/$$i ;\
	rm -f ${LIBDIR}/$$i; \
	done
	rm -rf ${INCDIR}/clens

.include <bsd.lib.mk>
