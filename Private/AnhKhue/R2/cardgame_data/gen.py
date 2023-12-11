import os
import random
random.seed(2392)

must_have = [[(10, 10, 30), (10, 10, 29), (9, 10, 30), (9, 9, 29)]]
rest = []
for n in range(11):
    for m in range(11):
        for c in range(1, 30 + 1):
            if (n, m, c) not in must_have:
                rest.append((n, m, c))

random.shuffle(rest)
each = 5
n_tests = 20
tests = must_have
for i in range(n_tests - 1):
    s = []
    for j in range(i * each, (i + 1) * each):
        s.append(rest[j])
    tests.append(s)

random.shuffle(tests)

cnt = 0
for test in tests:
    cnt += 1
    folder = "test" + (str(cnt) if cnt >= 10 else "0" + str(cnt))
    if (not os.path.exists(folder)):
        os.mkdir(folder)
    inp = folder + "/cardgame.inp"
    out = folder + "/cardgame.out"

    f = open(inp, "w")
    for (n, m, c) in test:
        f.write(str(n) + " " + str(m) + " " + str(c) + "\n")
    f.close()

    cmd = "./a.out < " + inp + " > " + out
    os.system(cmd)
