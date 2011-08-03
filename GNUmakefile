# $clens$

LIB.NAME = clens
LIB.SRCS = clens.c arc4random_buf.c strnvis.c strlcat.c strlcpy.c
LIB.SRCS += strtonum.c fmt_scaled.c fgetln.c fparseln.c
LIB.HEADERS = clens/clens.h 
LIB.HDRDIRS = clens

CPPFLAGS +=
INCFLAGS += -I include/clens
WARNFLAGS += -Wall -Werror
DEBUG += -g
CFLAGS += $(INCFLAGS) $(WARNFLAGS) $(DEBUG)
LDFLAGS += 


# Attempt to include platform specific makefile.
# OSNAME may be passed in.
OSNAME ?= $(shell uname -s)
OSNAME := $(shell echo $(OSNAME) | tr A-Z a-z)
-include config/Makefile.$(OSNAME)

# Default paths.
DESTDIR ?=
LOCALBASE ?= /usr/local
BINDIR ?= ${LOCALBASE}/bin
LIBDIR ?= ${LOCALBASE}/lib
INCDIR ?= ${LOCALBASE}/include

# Use obj directory if it exists.
OBJPREFIX ?= obj/
ifeq "$(wildcard $(OBJPREFIX))" ""
	OBJPREFIX =	
endif

# System utils.
AR ?= ar
CC ?= gcc
INSTALL ?= install
LN ?= ln
LNFLAGS ?= -sf
MKDIR ?= mkdir
RM ?= rm -f
RMDIR ?= rm -rf

vpath %.c src
vpath %.h include

LIB.OBJS = $(addprefix $(OBJPREFIX), $(LIB.SRCS:.c=.o))
LIB.DEPS = $(addsuffix .depend, $(LIB.OBJS))

all: $(OBJPREFIX)$(LIB.STATIC)

obj:
	-$(MKDIR) obj

$(OBJPREFIX)$(LIB.STATIC): $(LIB.OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(OBJPREFIX)%.o: %.c
	@echo "Generating $@.depend"
	@$(CC) $(INCFLAGS) -MM $(CPPFLAGS) $< | \
	sed 's,$*\.o[ :]*,$@ $@.depend : ,g' > $@.depend
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $< 

depend:
	@echo "Dependencies are automatically generated.  This target is not necessary."	

install:
	$(INSTALL) -m 0755 -d $(DESTDIR)$(LIBDIR)/
	$(INSTALL) -m 0644 $(OBJPREFIX)$(LIB.STATIC) $(DESTDIR)$(LIBDIR)/
	@for d in $(LIB.HDRDIRS); do \
		echo "$(INSTALL) -d -m 0755 $(DESTDIR)$(INCDIR)/$$d"; \
		$(INSTALL) -d -m 0755 $(DESTDIR)$(INCDIR)/$$d; \
	done
	@for hdr in $(LIB.HEADERS); do \
		echo "$(INSTALL) -m 0644 include/$$hdr $(DESTDIR)$(INCDIR)/$$hdr"; \
		$(INSTALL) -m 0644 include/$$hdr $(DESTDIR)$(INCDIR)/$$hdr; \
	done

uninstall:
	$(RM) $(DESTDIR)$(LIBDIR)/$(LIB.STATIC)
	$(RM) $(addprefix $(DESTDIR)$(INCDIR)/, $(LIB.HEADERS))
	$(RMDIR) $(addprefix $(DESTDIR)$(INCDIR)/, $(LIB.HDRDIRS))

clean:
	$(RM) $(LIB.OBJS)
	$(RM) $(OBJPREFIX)$(LIB.STATIC)
	$(RM) $(LIB.DEPS)


.PHONY: clean depend install uninstall

