.PHONY: all clean
.SILENT:

include make.h

all: libunp.a libunp.so

libunp.a: ${LIB_OBJS}
	$(AR) $(LIB_A_FLAGS) $@ ${LIB_OBJS}

libunp.so: ${LIB_OBJS}
	$(LD) $(LIB_SO_FLAGS) -o $@ ${LIB_OBJS}

${LIB_OBJ_DIR}/librw.o: ${LIB_SRC_DIR}/librw.c
	$(CC) $(CC_FLAGS) ${LIB_INCS} -o $@ $<

${LIB_OBJ_DIR}/liberr.o: ${LIB_SRC_DIR}/liberr.c
	$(CC) $(CC_FLAGS) ${LIB_INCS} -o $@ $<

clean:
	$(RM) ${LIB_OBJ_DIR}/*.o
	$(RM) libunp.a
	$(RM) libunp.so
