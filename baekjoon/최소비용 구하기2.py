## 다익스트라의 경우 노드 개수보다 엣지 개수가 월등히 많아 같은 노드로 가는 경로가 많은 경우, 26줄을 반드시 해줘야 한다.
## 생각해보면, cost가 현재 시작점으로부터 인덱스까지의 최소거리인데, curCost는 선택한 경로로부터 얻은 최소값이고 만약 원래 값이 더 작다면 볼 필요가 없다


import sys
import heapq

N = int(input())
M = int(input())

edges = [ [] for _ in range(N+1)]
for _ in range(M):
  u, v, cost = list(map(int, sys.stdin.readline().rstrip().split()))
  edges[u].append((v, cost))
start, end = list(map(int, sys.stdin.readline().rstrip().split()))

costs = [9087654321]*(N+1)
costs[start] = 0
h = []
heapq.heappush(h, (0, start))

prev = [0]*(N+1)
prev[start] = start
while h:
    curCost, cur = heapq.heappop(h)
    if costs[cur] < curCost:
       continue
    for adj, adjcost in edges[cur]:
       if costs[adj] > costs[cur]+adjcost:
          costs[adj] = costs[cur]+adjcost
          heapq.heappush(h, (costs[adj], adj))
          prev[adj] = cur

print(costs[end])
tmp = end
ways = [end]
while tmp != start:
    ways.append(prev[tmp])
    tmp = prev[tmp]
ways.reverse()
print(len(ways))
for way in ways:
    print(way, end= ' ')
exit(0)