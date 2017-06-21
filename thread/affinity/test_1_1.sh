#!/bin/bash
# 1 core, 1 buf
for((i=1; i<=32; i++)); do
    echo $i
    time ./test_affinity $i 1 1
done

