#!/usr/bin/bash

build "gen"
build "minesweeper"
build "minesweeper2"

while (true); do
    run "gen" -o "in"
    run "minesweeper" -i "in" -o "out"
    run "minesweeper2" -i "in" -o "ans"
    diff "out" "ans"
    if [ "$?" == "1" ]; then
        break
    fi
    
done
