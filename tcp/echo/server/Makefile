include ../make.h

all: echos

echos: echos.o
	$(CC) -o $@ echos.o -L${LIB_INC_BASE} -lunp

echos.o: echos.c
	$(CC) $(CC_FLAGS) -o $@ $<

clean:
	$(RM) echos.o echos
