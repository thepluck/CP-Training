import sys, resource
sys.setrecursionlimit(200000)
resource.setrlimit(resource.RLIMIT_STACK, (resource.RLIM_INFINITY, resource.RLIM_INFINITY))

def dfs(u, val, adj, dp):
    add = 0
    for v in adj[u]:
        dfs(v, val, adj, dp)
        add += dp[v][2]
    dp[u][0] = add - val[u]
    dp[u][1] = add + val[u]
    for v in adj[u]:
        dp[u][0] = max(dp[u][0], add - dp[v][2] + dp[v][0])
        dp[u][1] = max(dp[u][1], add - dp[v][2] + dp[v][1])
    dp[u][2] = max(dp[u][0] + val[u], dp[u][1] - val[u])

n = int(input())
val = list(map(int, input().split()))
adj = [[] for _ in range(0, n)]
dp = [[0] * 3 for _ in range(0, n)]

for _ in range(1, n):
    u, v = map(int, input().split())
    adj[u - 1].append(v - 1)

dfs(0, val, adj, dp)
print(dp[0][2])


