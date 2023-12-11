n = int(input())
f = 1; res = 1; n -= 2
while n > 0:
    f *= n; res += f; n -= 1
print(res)
