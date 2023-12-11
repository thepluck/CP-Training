#!/usr/bin/bash

build gen
build main
build sol

while true; do
    run gen -o "input.txt"
    run main -i "input.txt" -o "output.txt"
    run sol -i "input.txt" -o "answer.txt"
    diff "output.txt" "answer.txt"
    if [ "$?" == "1" ]; then
        break
    fi
done
