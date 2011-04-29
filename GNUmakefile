# $clens$

LOCALBASE ?= /usr/local
BINDIR ?= ${LOCALBASE}/bin
LIBDIR ?= ${LOCALBASE}/lib
INCDIR ?= ${LOCALBASE}/include
OBJPREFIX ?= obj/

# Clear object directory prefix if it doesn't exist.
ifeq "$(wildcard $(OBJPREFIX))" ""
	OBJPREFIX =	
endif

CC = gcc
INCFLAGS += -I include
WARNFLAGS += -Wall -Werror
DEBUG += -g
CFLAGS += $(INCFLAGS) $(WARNFLAGS) $(DEBUG)
LDFLAGS += 

vpath %.c src
vpath %.h include

LIB.NAME = clens
LIB.SRCS = arc4random_buf.c strnvis.c strlcat.c strlcpy.c fmt_scaled.c
LIB.HEADERS = clens.h
LIB.OBJS = $(addprefix $(OBJPREFIX), $(LIB.SRCS:.c=.o))
LIB.STATIC = lib$(LIB.NAME).a

all: $(OBJPREFIX)$(LIB.STATIC)

obj:
	-mkdir obj

$(OBJPREFIX)$(LIB.STATIC): $(LIB.OBJS)
	$(AR) crs $@ $^

$(OBJPREFIX)%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $< 

depend: $(LIB.SRCS)
	$(CC) $(INCFLAGS) -MM $^ > $(OBJPREFIX).depend

install:
	install -m 0644 $(OBJPREFIX)$(LIB.STATIC) $(LIBDIR)/
	install -m 0644 include/$(LIB.HEADERS) $(INCDIR)/
	
uninstall:
	rm -f $(LIBDIR)/$(LIB.STATIC)
	(cd $(INCDIR)/ && rm -f $(LIB.HEADERS))
	
clean:
	rm -f $(LIB.OBJS)
	rm -f $(OBJPREFIX)$(LIB.STATIC)
	rm -f $(OBJPREFIX).depend


.PHONY: clean depend install uninstall

