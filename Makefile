PROJECT = libFireBird

DIRS = av compression dialog flash fs fwpatches hdd hook iic imem ini InstructionSequences main mpvfd rec shutdown string tap tapapifix tapcom

BASE = $(shell cd /tapapi/TMS; pwd)
include ${BASE}/include/tool.mk

all:
	@for i in $(DIRS); \
	do \
	  cd $$i; \
	  make all; \
	  cd ..; \
	done
	-$(RM) $(PROJECT)_TMS.a
	@for i in $(DIRS); \
	do \
	  $(AR) -r $(PROJECT)_TMS.a $$i/*.o; \
	done
	@$(RANLIB) $(PROJECT)_TMS.a

clean:
	@for i in $(DIRS); do cd $$i; make clean; cd ..; done
