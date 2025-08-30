import sys
from collections import deque

N, M = list(map(int, input().rstrip().split()))

edges = [[] for _ in range(N + 1)]

indegree = [0] * (N + 1)

for _ in range(M):
    u, v = list(map(int, sys.stdin.readline().rstrip().split()))
    edges[u].append(v)
    indegree[v] += 1

start = 0
res = []

q = deque()
for i in range(1, len(indegree)):
    if indegree[i] == 0:
        q.append(i)


while len(q) > 0:
    cur = q.popleft()
    res.append(cur)
    for adj in edges[cur]:
        indegree[adj] -= 1
        if indegree[adj] == 0:
            q.append(adj)


for i in range(len(res)):
    if i > 0:
        print(" ", end="")
    print(res[i], end="")
