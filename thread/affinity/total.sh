#!/bin/bash
# 1 core, 1 buf
#./test_1_1.sh > rlt.1.1 2>&1 | tail -f rlt.1.1
#./test_1_128.sh > rlt.1.128 2>&1 | tail -f rlt.1.128
#./test_2_1.sh > rlt.2.1 2>&1 | tail -f rlt.2.1
./test_2_128.sh > rlt.2.128 2>&1 | tail -f rlt.2.128

