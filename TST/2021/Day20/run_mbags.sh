#!/usr/bin/bash

build mbags

for ((i=0;i<10;i++))
do
    eval "run mbags -i input/input_$i.txt -o submission/output_$i.txt"
done
