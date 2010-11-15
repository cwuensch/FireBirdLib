PROJECT = libFireBird

DIRS = av compression debug elf flash FontManager hdd ini InstructionSequences main rec shutdown string StringDB tap tapcom time TMSOSDMenu tmsvfd

BASE = $(shell cd /tapapi/TMS; pwd)
include ${BASE}/include/tool.mk

all:
	@for i in $(DIRS); \
	do \
	  cd $$i; \
	  make all; \
	  cd ..; \
	done
	-$(RM) $(PROJECT).a
	@for i in $(DIRS); \
	do \
	  $(AR) -r $(PROJECT).a $$i/*.o; \
	done
	@$(RANLIB) $(PROJECT).a

clean:
	@for i in $(DIRS); do cd $$i; make clean; cd ..; done
