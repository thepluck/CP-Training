#!/usr/bin/bash

build halfhalf

for input_file in testcases/*.in; do
    printf "$input_file\n"
    eval "./run.sh halfhalf.cpp $input_file"
done