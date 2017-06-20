#!/bin/bash

for((i=1; i<=32; i++)); do
    echo $i
    time ./test_affinity $i 2 2
done
