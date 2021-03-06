include taps.mak

CFLAGS += -DOS=\"$(OS)\" -Wall -I.
LDFLAGS += -Wl,-Map,$*.map

all: Caller.tap Callee.tap

Caller.elf: Caller.o
	@echo "[Linking...]" 
	$(LINK) $(LDFLAGS) -o $@ Caller.o $(LDLIBS) 

Callee.elf: Callee.o
	@echo "[Linking...]" 
	$(LINK) $(LDFLAGS) -o $@ Callee.o $(LDLIBS) 
