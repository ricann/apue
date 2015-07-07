include ${UNP_BASE}/make.h

all: mainpipe

mainpipe: mainpipe.o client.o server.o
	$(CC) -o $@ mainpipe.o client.o server.o -L${LIB_BASE} -lunp

mainpipe.o: mainpipe.c
	$(CC) $(CC_FLAGS) -I${LIB_INC_BASE} -o $@ $<

client.o: client.c
	$(CC) $(CC_FLAGS) -I${LIB_INC_BASE} -o $@ $<

server.o: server.c
	$(CC) $(CC_FLAGS) -I${LIB_INC_BASE} -o $@ $<

clean:
	$(RM) mainpipe.o mainpipe
