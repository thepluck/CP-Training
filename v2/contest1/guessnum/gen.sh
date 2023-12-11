#!bash

build gen

for sumn in {81..100}; do
  eval "./gen -sumn ${sumn} -test 1 > tests/sub1_dec${sumn}.in"
done

eval "./gen -sumn 100 -test 10 > tests/sub1_sum.in"

for sumn in {481..500}; do
  eval "./gen -sumn ${sumn} -test 1 > tests/sub2_dec${sumn}.in"
done

eval "./gen -sumn 500 -test 20 > tests/sub2_sum.in"

for sumn in {4981..5000}; do
  eval "./gen -sumn ${sumn} -test 1 > tests/sub3_dec${sumn}.in"
done

eval "./gen -sumn 5000 -test 50 > tests/sub3_sum.in"