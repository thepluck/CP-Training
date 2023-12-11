#!/usr/bin/bash

build lcsss2
build check_lcsss
eval "> log.txt"

for id in {00..99}
do
    eval "run lcsss2 -i lcsss_data/lcsss$id.in -o lcsss_data/lcsss$id.out"
    eval "echo test $id: >> log.txt"
    eval "./check_lcsss lcsss_data/lcsss$id.in lcsss_data/lcsss$id.ans lcsss_data/lcsss$id.out >> log.txt"
done
