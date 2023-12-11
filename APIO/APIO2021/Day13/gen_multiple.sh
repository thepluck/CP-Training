#!/usr/bin/bash

build gen_single
build army_full

for id in {00..49}; do
    eval "run gen_single -o test_army/$id.in"
    eval "run army_full -i test_army/$id.in -o test_army/$id.out"
done