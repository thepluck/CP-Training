#!bash

build gen

for cnt in {0..20}; do
  let bias=(cnt-10)*10
  eval "./gen -sub 1 -type rand -bias ${bias} > tests/sub1_${cnt}.in"
  eval "./gen -sub 2 -type rand -bias ${bias} > tests/sub2_${cnt}.in"
  eval "./gen -sub 3 -type rand -bias ${bias} > tests/sub3_${cnt}.in"
  eval "./gen -sub 4 -type rand -bias ${bias} > tests/sub4_${cnt}.in"
done

eval "./gen -sub 1 -type inc > tests/sub1_21.in"
eval "./gen -sub 1 -type dec > tests/sub1_22.in"

eval "./gen -sub 2 -type inc > tests/sub2_21.in"
eval "./gen -sub 2 -type dec > tests/sub2_22.in"

eval "./gen -sub 3 -type inc > tests/sub3_21.in"
eval "./gen -sub 3 -type dec > tests/sub3_22.in"

eval "./gen -sub 4 -type inc > tests/sub4_21.in"
eval "./gen -sub 4 -type dec > tests/sub4_22.in"