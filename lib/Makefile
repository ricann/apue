include make.h

all: libunp.a libunp.so

libunp.a: libunp.o
	$(CC) $(lIB_A_FLAGS) -o $@ $<

libunp.so: libunp.o
	$(CC) $(lIB_SO_FLAGS) -o $@ $<

libunp.o: libunp.c
	$(CC) $(CC_FLAGS) -o $@ $<


clean:
	$(RM) *.o
	$(RM) libunp.a
	$(RM) libunp.so
