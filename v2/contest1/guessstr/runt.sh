#!/usr/bin/bash

for file in tests/*.in; do
  filename="${file%.*}"
  eval "run grader -i ${file} -o ${filename}.out"
done