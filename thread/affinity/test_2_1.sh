#!/bin/bash
# 2 core, 1 buf
for((i=1; i<=32; i++)); do
    echo $i
    time ./test_affinity $i 2 1
done
