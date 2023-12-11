#!/bin/bash

problem=jumps
solution=jumps_full
grader_name=stub

g++ -std=gnu++17 -O2 -pipe -o "${problem}" "${grader_name}.cpp" "${problem}.cpp"
g++ -std=gnu++17 -O2 -pipe -o "${solution}" "${grader_name}.cpp" "${solution}.cpp"
