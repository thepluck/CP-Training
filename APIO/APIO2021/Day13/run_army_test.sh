#!/usr/bin/bash

build army

for id in {00..49}; do
    eval "run army -i test_army/$id.in -o out"
    eval "diff test_army/$id.out out"
    if [ "$?" == "1" ]; then
        printf "Wrong answer on test $id"
    fi
done