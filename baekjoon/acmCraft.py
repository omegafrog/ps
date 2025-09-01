import sys

T = int(input())


def backTracking(n, adj, dp, cost):
    if len(adj[n]) == 0:
        dp[n] = cost[n]
        return cost[n]
    res = -1
    for node in adj[n]:
        if dp[node] != -1:
            res = max(res, dp[node])
        else:
            res = max(res, backTracking(node, adj, dp, cost))
    dp[n] = res + cost[n]
    return dp[n]


for _ in range(T):
    N, K = list(map(int, input().rstrip().split()))
    cost = [0] + list(map(int, sys.stdin.readline().rstrip().split()))

    adj = [[] for _ in range(N + 1)]
    for _ in range(K):
        u, v = list(map(int, sys.stdin.readline().rstrip().split()))
        adj[v].append(u)

    dp = [-1] * (N + 1)
    target = int(input())
    res = -1
    for node in adj[target]:
        tmp = backTracking(node, adj, dp, cost)
        # print(node, tmp)
        res = max(res, tmp)
    if res == -1:
        print(cost[target])
    else:
        print(res + cost[target])
