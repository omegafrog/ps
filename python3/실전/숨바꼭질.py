import sys
import heapq

INF = 987654321
N, M = list(map(int, sys.stdin.readline().rstrip().split()))

roads = []
adj = [INF] * (N + 1)

for _ in range(N + 1):
    roads.append([] * (N + 1))


for _ in range(M):
    u, v = list(map(int, sys.stdin.readline().rstrip().split()))
    roads[u].append(v)
    roads[v].append(u)

visited = [0] * (N + 1)

heap = []

heapq.heappush(heap, (0, 1))
visited[1] = 1
adj[1] = 0

while heap:
    curVal, curPos = heapq.heappop(heap)
    for nextPos in roads[curPos]:
        if visited[nextPos] == 0 and adj[nextPos] > adj[curPos] + 1:
            adj[nextPos] = adj[curPos] + 1
            visited[nextPos] = 1
            heapq.heappush(heap, (adj[nextPos], nextPos))


print(adj)

biggestVal = -1
biggestPos = []

for pos in range(2, N + 1):
    if adj[pos] > biggestVal:
        biggestPos.clear()
        biggestVal = adj[pos]
        biggestPos.append(pos)
    elif adj[pos] == biggestVal:
        biggestPos.append(pos)

print(biggestPos[0], biggestVal, len(biggestPos))
