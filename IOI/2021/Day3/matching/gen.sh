#!/usr/bin/bash

build gen
g++ -std=c++14 -O2 matching_full.cpp grader.cpp -o matching_full

for id in {00..99}; do
    eval "run gen -o test/$id.in"
    eval "run matching_full -i test/$id.in -o test/$id.out"
done
