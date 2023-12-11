#!/usr/bin/bash

build cardgame
for id in {01..20}; do
    eval "cp cardgame_data/test$id/cardgame.inp input.txt"
    eval "run cardgame -i input.txt -o output.txt"
    eval "diff output.txt cardgame_data/test$id/cardgame.out"
    if [ "$?" == "1" ]; then
        printf "Wrong answer at test $id"
    fi
done
