#compile related
CC = echo $(notdir $<);gcc
AS = as
LD = echo $(notdir $@);gcc
RM = rm
MAKE = make
MKDIR = mkdir

CC_FLAGS = -c -g -O2 -Wall
LD_FLAGS =
RM_FLAGS = -f
MKDIR_FLAGS =

#related directories
LIB_BASE = ${UNP_BASE}/lib
LIB_INC_BASE = ${UNP_BASE}/lib/inc
TCP_ECHO_BASE = ${UNP_BASE}/tcp/echo
