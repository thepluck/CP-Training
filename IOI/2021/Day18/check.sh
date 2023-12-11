#!/usr/bin/bash

build points1
build points1_naive
build points1_gen

while true; do
    eval "run points1_gen -o in"
    eval "run points1 -i in -o out"
    eval "run points1_naive -i in -o ans"
    eval "diff out ans"
    if [ "$?" == "1" ]; then
        break
    fi
done