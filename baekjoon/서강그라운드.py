import heapq
import sys

N, M, R = list(map(int, input().rstrip().split()))

numOfItem = [0]

numOfItem = numOfItem + list(map(int, input().rstrip().split()))

edges = [{} for _ in range(N + 1)]

for _ in range(R):
    u, v, t = list(map(int, sys.stdin.readline().rstrip().split()))
    if v in edges[u] and edges[u][v] > t:
        edges[u][v] = t
    elif v not in edges[u]:
        edges[u][v] = t

    if u in edges[v] and edges[v][u] > t:
        edges[v][u] = t
    elif u not in edges[v]:
        edges[v][u] = t


def dijkstra(start):
    dist = [987654321] * (N + 1)
    dist[start] = 0
    heap = []
    heapq.heappush(heap, [0, start])

    while len(heap) > 0:
        curDist, curIdx = heapq.heappop(heap)

        for adj in edges[curIdx]:
            weight = edges[curIdx][adj]
            if dist[adj] > dist[curIdx] + weight:
                dist[adj] = dist[curIdx] + weight
                heapq.heappush(heap, [dist[adj], adj])
    return dist


res = -1
# print(numOfItem)

for i in range(1, N + 1):
    cnt = 0
    dist = dijkstra(i)
    for node in range(1, len(dist)):
        if dist[node] <= M:
            cnt += numOfItem[node]

    # print(i, dist, cnt)
    res = max(res, cnt)

print(res)
