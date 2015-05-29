#compile related
CC = echo $(notdir $<);gcc
AS = as
AR = echo $(notdir $<);ar
LD = echo $(notdir $@);ld
RM = rm
MAKE = make
MKDIR = mkdir

CC_FLAGS = -c -g -O2 -Wall
LIB_A_FLAGS = -r
LIB_SO_FLAGS = -shared -fPic
LD_FLAGS =
RM_FLAGS = -f
MKDIR_FLAGS =

LIB_BASE = ${UNP_BASE}/lib
LIB_INC_DIR = ${UNP_BASE}/lib/inc
LIB_SRC_DIR = ${UNP_BASE}/lib/src
LIB_OBJ_DIR = ${UNP_BASE}/lib/obj

LIB_INC = -I${LIB_INC_DIR}
