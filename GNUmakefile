# $clens$

LIB.NAME = clens
LIB.SRCS = arc4random_buf.c strnvis.c strlcat.c strlcpy.c fmt_scaled.c
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
	install -m 0644 $(OBJPREFIX)$(LIB.STATIC) $(LIBDIR)/
	@for d in $(LIB.HDRDIRS); do \
		echo "install -d -m 0755 $(INCDIR)/$$d"; \
		install -d -m 0755 $(INCDIR)/$$d; \
	done
	@for hdr in $(LIB.HEADERS); do \
		echo "install -m 0644 include/$$hdr $(INCDIR)/$$hdr"; \
		install -m 0644 include/$$hdr  $(INCDIR)/$$hdr; \
	done
	
uninstall:
	$(RM) $(LIBDIR)/$(LIB.STATIC)
	(cd $(INCDIR)/ && $(RM) $(LIB.HEADERS))
	(cd $(INCDIR)/ && $(RMDIR) $(LIB.HDRDIRS))
	
clean:
	$(RM) $(LIB.OBJS)
	$(RM) $(OBJPREFIX)$(LIB.STATIC)
	$(RM) $(OBJPREFIX).depend


.PHONY: clean depend install uninstall

