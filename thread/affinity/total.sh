#!/bin/bash
# 1 core, 1 buf
echo test_1_1.sh
#./test_1_1.sh > rlt.1.1 2>&1
echo test_1_1024.sh
./test_1_1024.sh > rlt.1.1024 2>&1
echo test_4_1.sh
#./test_4_1.sh > rlt.4.1 2>&1
echo test_4_1024.sh
./test_4_1024.sh > rlt.4.1024 2>&1

