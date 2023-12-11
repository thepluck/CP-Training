#!/usr/bin/bash

./compile_cpp.sh

> log.txt

for id in {00..99}; do
    eval "run matching -i test/$id.in -o out"
    eval "diff test/$id.out out"
    if [ "$?" == "1" ]; then
        printf "Wrong answer at test $id\n" >> log.txt
    fi
done
