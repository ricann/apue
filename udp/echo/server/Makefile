include ../make.h

all: echos

echos: echos.o
	$(CC) -o $@ echos.o

echos.o: echos.c
	$(CC) $(INC) $(CC_FLAGS) -o $@ $<

clean:
	$(RM) echos.o echos
