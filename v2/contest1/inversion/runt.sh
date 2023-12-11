#!/usr/bin/bash

for file in tests/*.in; do
  filename="${file%.*}"
  eval "run print_again -i ${file} -o ${filename}.out"
done