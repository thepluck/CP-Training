#!/usr/bin/bash

build latgach

for cnt in {1..5}; do
    run latgach -i "input/input_${cnt}.txt" -o "output/output_${cnt}.txt"
done