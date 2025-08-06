import sys
import heapq

N, M, X = list(map(int, input().rstrip().split()))

adjs = [[] for _ in range(N + 1)]
edges = [[0] * (N + 1) for _ in range(N + 1)]

heap = []

dist1 = [987654321] * (N + 1)

for _ in range(M):
    u, v, t = list(map(int, sys.stdin.readline().rstrip().split()))
    edges[u][v] = t
    adjs[u].append([v, t])


def dijkstra(i, dist):
    heap = []
    heapq.heappush(heap, [0, i])
    while len(heap) > 0:
        weight, cur = heapq.heappop(heap)
        for adj in adjs[cur]:
            next = adj[0]
            nextWeight = adj[1]
            if dist[cur] + nextWeight < dist[next]:
                dist[next] = dist[cur] + nextWeight
                heapq.heappush(heap, [dist[next], next])


xToHomeDist = list(dist1)
xToHomeDist[X] = 0
dijkstra(X, xToHomeDist)

XToHome = -1
for i in xToHomeDist:
    if i == 987654321:
        continue
    XToHome = max(XToHome, i)

biggestN = 0
homeToX = -1

res = -1


for i in range(1, N + 1):
    dist = list(dist1)
    dist[i] = 0
    dijkstra(i, dist)
    res = max(res, dist[X] + xToHomeDist[i])


print(res)
