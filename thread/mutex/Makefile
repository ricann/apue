include ${UNP_BASE}/make.h
include make.h

mutex_test: mutex_test.o
	$(CC) -o $@ $< -lpthread

mutex_test.o: mutex_test.c
	$(CC) $(CC_FLAGS) -I${LIB_INC_BASE} -o $@ $<

clean:
	$(RM) mutex_test.o mutex_test
