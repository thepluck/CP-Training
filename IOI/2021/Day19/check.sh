#!/usr/bin/bash

build math_tree
build naive
build gen

while true; do
    eval "run gen -o in"
    eval "run math_tree -i in -o out"
    eval "run naive -i in -o ans"
    eval "diff out ans"
    if [ "$?" == "1" ]; then
        break
    fi
done