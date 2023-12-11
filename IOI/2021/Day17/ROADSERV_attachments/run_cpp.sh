#!/usr/bin/bash

build roadserv

for id in {02..06}; do
    eval "run roadserv -i input_$id.txt -o submission/output_$id.txt"
done