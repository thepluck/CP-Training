#!/usr/bin/bash

build dprod
build checkdprod

for idx in {01..20}; do
    run dprod -i "test${idx}/dprod.inp" -o "test${idx}/dprod.out"
    ./checkdprod "test${idx}/dprod.inp" "test${idx}/dprod.ans" "test${idx}/dprod.out"
done