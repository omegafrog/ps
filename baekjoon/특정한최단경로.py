import sys
import heapq

N, E = list(map(int, input().rstrip().split()))

adjs = [[] for _ in range(N + 1)]
edges = [[0] * (N + 1) for _ in range(N + 1)]


for _ in range(E):
    u, v, w = list(map(int, sys.stdin.readline().rstrip().split()))
    adjs[u].append(v)
    adjs[v].append(u)
    edges[u][v] = w
    edges[v][u] = w

V1, V2 = list(map(int, input().rstrip().split()))

dist = [987654321 for _ in range(N + 1)]

# print(adjs)
# print(edges)


def dijkstra(start, end, dist, edges):
    stack = []
    heapq.heappush(stack, [0, start])
    dist[start] = 0
    while len(stack) > 0:
        [weight, cur] = heapq.heappop(stack)
        for adj in adjs[cur]:
            if dist[cur] + edges[cur][adj] < dist[adj]:
                dist[adj] = dist[cur] + edges[cur][adj]
                heapq.heappush(stack, [dist[adj], adj])


tmpDist = list(dist)
dijkstra(1, N, tmpDist, edges)
startToV1 = tmpDist[V1]
startToV2 = tmpDist[V2]

tmpDist = list(dist)

dijkstra(V1, V2, tmpDist, edges)
V1ToV2 = tmpDist[V2]
tmpDist = list(dist)
dijkstra(V2, N, tmpDist, edges)
V2ToN = tmpDist[N]
dijkstra(V2, V1, tmpDist, edges)
V2ToV1 = tmpDist[V1]
tmpDist = list(dist)
dijkstra(V1, N, tmpDist, edges)
V1ToN = tmpDist[N]

if startToV1 == 987654321 or V1ToV2 == 987654321 or V2ToN == 987654321:
    print(-1)
elif startToV2 == 987654321 or V2ToV1 == 987654321 or V1ToN == 987654321:
    print(-1)
else:
    print(min(startToV1 + V1ToV2 + V2ToN, startToV2 + V2ToV1 + V1ToN))
