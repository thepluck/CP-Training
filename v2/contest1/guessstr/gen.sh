#!/usr/bin/bash

for idx in {0..20}; do
  let bias=idx-10
  eval "./only012 -bias ${bias} > tests/full_${idx}.txt"
done