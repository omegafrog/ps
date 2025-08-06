import sys

INF = 987654321


def bellmanFod(edges, N, start):
    dist = [INF] * (N + 1)
    dist[start] = 0
    for i in range(N):
        for edge in edges:
            u, v, t = edge
            if dist[u] != INF and dist[v] > dist[u] + t:
                dist[v] = dist[u] + t
                if i == N - 1:
                    return False, []
    return True, dist


T = int(input())


for _ in range(T):
    N, M, W = list(map(int, input().rstrip().split()))
    edges = []
    for _ in range(M):
        S, E, T = list(map(int, sys.stdin.readline().rstrip().split()))
        edges.append((S, E, T))
        edges.append((E, S, T))

    for _ in range(W):
        S, E, T = list(map(int, sys.stdin.readline().rstrip().split()))
        edges.append((S, E, -1 * T))

    for i in range(1, N + 1):
        edges.append((N + 1, i, 0))

    res, dist = bellmanFod(edges, N + 1, N + 1)
    # print(dist)
    if res:
        print("NO")
    else:
        print("YES")

