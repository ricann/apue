#!/bin/bash
# 1 core, 128 buf
for((i=1; i<=32; i++)); do
    echo $i
    time ./test_affinity $i 1 128
done
