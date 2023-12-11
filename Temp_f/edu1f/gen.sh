#!/usr/bin/bash

mkdir test

for cnt in {01..42}; do
    ./gen.py > "test/$cnt"
done