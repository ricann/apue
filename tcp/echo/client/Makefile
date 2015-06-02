include ../make.h

all: echoc

echoc: echoc.o
	$(CC) -o $@ echoc.o -L${LIB_BASE} -lunp

echoc.o: echoc.c
	$(CC) $(CC_FLAGS) -I${LIB_INC_BASE} -o $@ $<

clean:
	$(RM) echoc.o echoc
