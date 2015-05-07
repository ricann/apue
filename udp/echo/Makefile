.PHONY: all clean
.SILENT:

include make.h

all:
	$(MAKE) -w -C $(ECHO_BASE)/server
	$(MAKE) -w -C $(ECHO_BASE)/client

clean:
	$(MAKE) -w -C $(ECHO_BASE)/server clean
	$(MAKE) -w -C $(ECHO_BASE)/client clean
