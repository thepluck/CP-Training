class edge:
    def __init__(self, u, v, w):
        self.u = u
        self.v = v
        self.w = w

    def __lt__(self, other):
        return self.w < other.w

class dsu:
    def __init__(self, n):
        self.n = n
        self.p = [range(0, n)]

    def find(self, u):
        if (u != self.p[u]):
            self.p[u] = self.find(self.p[u])
        return self.p[u]

    def union(self, u, v):
        u = self.find(u)
        v = self.find(v)
        if (u == v):
            return False
        self.p[v] = u
        return True


n, m = map(int, input().split())
lst = []
for i in range(0, m):
    u, v, w = map(int, input().split())
    lst.append(edge(u, v, w))
lst.sort()
ds = dsu(n)
tot = 0
for e in lst:
    if (ds.union(e.u, e.v)):
        tot += e.w
print(tot)

