@echo off
SETLOCAL
set NAME=matching

g++ -o %NAME% grader.cpp %NAME%.cpp -O2 -lm -std=c++11
ENDLOCAL
