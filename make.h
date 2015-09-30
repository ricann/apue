#---------------compile related--------
CC = @echo $(notdir $<);gcc
CC_NO_ECHO = gcc
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

#--------related directories-----------
LIB_BASE = ${UNP_BASE}/lib
LIB_INC_BASE = ${UNP_BASE}/lib/inc
