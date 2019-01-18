PROJECT = libFireBird

DIRS = av compression debug elf EPG ExtAttribs Firmware flash FontManager hdd ini InstructionSequences LogoManager main rec shutdown string StringDB tap tapcom time TMSOSDMenu TMSOSDKeyboard tmsvfd

export SRC_DIR = $(shell pwd)

BASE = $(shell cd /tapapi/TMS; pwd)
include ${BASE}/include/tool.mk

# normal library version and debugging control by TAP
CFLAGS = -DFB_CALL_TRACE
#CFLAGS = -DFB_DEBUG      for a special debugging version
#CFLAGS = -DFB_DEBUG_FULL for a special debugging version incl. trace support

export CFLAGS

all: lib devutils

docs: HTMLDOCS

.PHONY: doc

doc:
	markdown README.md >README.html

lib:
	@for i in $(DIRS); \
	do \
	  cd $$i; \
	  $(MAKE) all; \
	  cd ..; \
	done
	-$(RM) $(PROJECT).a
	@for i in $(DIRS); \
	do \
	  $(AR) -r $(PROJECT).a $$i/*.o; \
	done
	@$(RANLIB) $(PROJECT).a

.PHONY:	devutils

devutils:
	cd $@; \
	$(MAKE) all;

clean:
	@for i in $(DIRS); do cd $$i; make clean; cd ..; done
	cd devutils; make clean; cd ..;
	rm -rf $(PROJECT).a HTMLDOCS README.html

.PHONY: HTMLDOCS

HTMLDOCS:
	rm -rf $@
	doxygen
