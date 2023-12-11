#!/usr/bin/bash

build gen_lcsss

for id in {00..99}
do
    eval "run gen_lcsss -o lcsss_data/lcsss$id.in"
    eval "run lcsss -i lcsss_data/lcsss$id.in -o lcsss_data/lcsss$id.ans"
done
