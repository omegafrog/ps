import heapq

V, E = list(map(int, input().rstrip().split()))

edges = [[] for _ in range(V + 1)]

weights = [[987654321] * (V + 1) for _ in range(V + 1)]


K = int(input())
for _ in range(E):
    u, v, w = list(map(int, input().rstrip().split()))
    edges[u].append([v, w])


heap = []

dist = [987654321] * (V + 1)
dist[K] = 0

heapq.heappush(heap, [0, K])

while len(heap) > 0:
    weight, cur = heapq.heappop(heap)
    for next, weight in edges[cur]:
        if dist[next] > dist[cur] + weight:
            dist[next] = dist[cur] + weight
            heapq.heappush(heap, [dist[next], next])

for i in range(1, V + 1):
    if dist[i] == 987654321:
        print("INF")
    else:
        print(dist[i])
