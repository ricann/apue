include ../make.h

all: echoc

echoc: echoc.o
	$(CC) -o $@ echoc.o

echoc.o: echoc.c
	$(CC) $(INC) $(CC_FLAGS) -o $@ $<

clean:
	$(RM) echoc.o echoc
