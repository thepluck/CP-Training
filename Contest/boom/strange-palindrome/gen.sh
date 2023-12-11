#!/usr/bin/bash


build gen

for id in {00..49}; do
    eval "run gen -o $id.in"
done
