#!/usr/bin/bash

build gen

for id in {00..19}; do
    eval "./gen 3000 > $id.in"
done

for id in {20..39}; do
    eval "./gen 100000 > $id.in"
done
