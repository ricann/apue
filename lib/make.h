
#----------------path------------------
LIB_INC_DIR = ${UNP_BASE}/lib/inc
LIB_SRC_DIR = ${UNP_BASE}/lib/src
LIB_OBJ_DIR = ${UNP_BASE}/lib/obj


#---------------variables--------------
LIB_INCS = -I${LIB_INC_DIR}
LIB_OBJS = ${LIB_OBJ_DIR}/librw.o \
          ${LIB_OBJ_DIR}/libsock.o \
          ${LIB_OBJ_DIR}/wrapsock.o \
          ${LIB_OBJ_DIR}/liberr.o \
          ${LIB_OBJ_DIR}/wrapunix.o \
          ${LIB_OBJ_DIR}/wrapstdio.o
