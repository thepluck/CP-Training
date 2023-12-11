#!/usr/bin/bash

build cactus-MST2

eval "> log.txt"

for id in {00..99}
do
    eval "timeout 2 run cactus-MST2 -i cactus_data/$id.inp -o cactus_data/$id.ans"
    eval "diff cactus_data/$id.ans cactus_data/$id.out >> log.txt"
    if [ "$?" == "1" ]
    then
        printf "Wrong answer at test $id"
    fi
done
