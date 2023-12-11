#!/usr/bin/python3

from cyaron import *
import random
import sys

n = 1000
m = 100

a = Vector.random(n, [200000, 200000], 2)
b = Vector.random(m, [200000, 200000, 200000, 200000], 2)

for i in range(len(a)):
    for j in range(len(a[i])):
        a[i][j] -= 100000
        a[i][j] = round(a[i][j], 2)

for i in range(len(b)):
    for j in range(len(b[i])):
        b[i][j] -= 100000
        b[i][j] = round(b[i][j], 2)

print(n, end=' ')
print(m)
a = Polygon.simple_polygon(a).points

for i in range(len(a)):
    for j in range(len(a[i])):
        print(f"{a[i][j]:.2f}", end='')
        if j + 1 == len(a[i]):
            print('')
        else :
            print(' ', end='')

for i in range(len(b)):
    for j in range(len(b[i])):
        print(f"{b[i][j]:.2f}", end='')
        if j + 1 == len(b[i]):
            print('')
        else :
            print(' ', end='')

