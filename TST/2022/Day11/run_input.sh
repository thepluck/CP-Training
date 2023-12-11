#!/usr/bin/bash

build "klimit"

for index in {2..9}; do
    run "klimit" -i "input/input_${index}.txt" -o "output/output_${index}.txt"
done