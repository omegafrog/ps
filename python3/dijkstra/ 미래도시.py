import sys
import heapq

[N, M] = list(map(int, sys.stdin.readline().rstrip().split()))
g = []
g2=[]

for i in range(N+1):
    g.append([])
    g2.append([987654321]*(N+1))

for i in range(N+1):
    g2[i][i] = 0



for i in range(M):
    tmp = list(map(int, sys.stdin.readline().rstrip().split()))
    g2[tmp[0]][tmp[1]] = 1
    g2[tmp[1]][tmp[0]] = 1
    g[tmp[0]].append(tmp[1])
    g[tmp[1]].append(tmp[0])

visited = [False]*(N+1)

[X, K] = list(map(int, sys.stdin.readline().rstrip().split()))

smallest = [987654321]*(N+1)

smallest[1] = 0


h =[]
heapq.heappush(h, (0, 1))

while len(h)>0:
    cur = heapq.heappop(h)
    for node in g[cur[1]]:
        if visited[node]==False and smallest[node] > cur[0]+1:
            visited[node]=True
            smallest[node] = cur[0]+1
            heapq.heappush(h,(smallest[node], node))

print(smallest)
print(smallest[K]+smallest[X])

for n in range(1, N):
    for a in range(1,N+1):
        for b in range(1,N+1):
            if g2[a][b] > g2[a][n]+g2[n][b]:
                g2[a][b] = g2[a][n]+g2[n][b]

print(g2)
print(g2[1][K]+g2[K][X])