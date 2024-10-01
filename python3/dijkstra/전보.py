import sys
import heapq

[N,M,C] = list(map(int, sys.stdin.readline().rstrip().split()))

adj = []
g = []
for i in range(N+1):
    adj.append([])
    g.append([0]*(N+1))


for i in range(M):
    [u, v, t] = list(map(int, sys.stdin.readline().rstrip().split()))
    g[u][v] = t
    adj[u].append([v,t])

visited = [False]*(N+1)

h = []

smallest = [987654321]*(N+1)
smallest[C] = 0
heapq.heappush(h, (0, C))

while len(h)>0:
    cur = heapq.heappop(h)
    [time, pos] = cur
    for [nextPos, nextTime] in adj[pos]:
        if visited[nextPos] == False and smallest[nextPos] > time + nextTime:
            visited[nextPos] = True
            smallest[nextPos] = time + g[pos][nextPos]
            heapq.heappush(h, (smallest[nextPos], nextPos))

cityCnt = 0
maxCityTime = -1
for i in range(1,N+1):
    if i == C: continue
    if smallest[i] != 987654321:
        cityCnt+=1
        maxCityTime = max(maxCityTime, smallest[i])

print(cityCnt, maxCityTime)
print(smallest)