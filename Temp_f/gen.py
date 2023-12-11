import random

def testcase(inp):
    n, q = 10000, 10000
    print(n, file=inp)
    for i in range(2, n + 1):
        print(i, random.randint(1, i - 1), random.randint(1, 1000), file=inp)
    for _ in range(0, q):
        print('QUERY', random.randint(1, n), random.randint(1, n), file=inp)
    print('DONE', file=inp)

t = int(input())
with open("input.txt", 'w') as inp:
    print(t, file=inp)
    for _ in range(0, t):
        testcase(inp)





