from math import ceil
from math import log10
import sys

input = sys.stdin.readline


def inp():
    return int(input())


p, q = map(int, input().split())

d = ceil(pow(p / q, 1 / 5))

# sum 1^5+2^5+...+x^5


def calc(d):
    return (d - 1) * (d - 1) * d * d * (d * d * 2 - 2 * d - 1) // 12

start = p * d - calc(d) * q

print(start)

l = 1
r = 10 ** 18

while l < r:
    mid = (l + r) // 2
    if start + calc(mid + 1) * q - p * d >= 10 ** 99:
        r = mid
    else:
        l = mid + 1

print(l)
