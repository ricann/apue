.PHONY: all clean
.SILENT:


include make.h

all: libunp.a libunp.so

libunp.a: libunp.o
	$(AR) $(LIB_A_FLAGS) $@ $<

libunp.so: libunp.o
	$(LD) $(LIB_SO_FLAGS) -o $@ $<

libunp.o: libunp.c
	$(CC) $(CC_FLAGS) -o $@ $<


clean:
	$(RM) *.o
	$(RM) libunp.a
	$(RM) libunp.so
