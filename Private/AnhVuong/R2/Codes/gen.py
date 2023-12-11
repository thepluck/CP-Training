import random

n, q = 10, 10

nonempty = set()

with open("input.txt", "w") as fi:
    print(n, file=fi)
    for i in range(2, n + 1):
        print(i, random.randint(1, i - 1), file=fi)
    print(q, file=fi)
    for _ in range(0, q):
        u = random.randint(1, n)
        t = 3
        if not (u in nonempty):
            t = random.randint(1, 2)
            nonempty.add(u)
        else:
            nonempty.discard(u)
        print(t, u, file=fi)


