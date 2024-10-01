## elapsed : 21:48
## solved

import sys
from collections import deque

N, M, K, X = map(int, sys.stdin.readline().rstrip().split())

q = deque()

nodes = []

for i in range(N + 1):
    nodes.append([])

for _ in range(M):
    u, v = map(int, sys.stdin.readline().rstrip().split())
    nodes[u].append(v)

q.append([X, 0])
visited = [0] * (N + 1)
visited[X] = 1


res = []
while len(q) > 0:
    curNode, curLength = q.popleft()
    if curLength == K:
        res.append(curNode)
    if curLength > K:
        break

    for adj in nodes[curNode]:
        if visited[adj] == 0:
            visited[adj] = 1
            q.append([adj, curLength + 1])

res.sort()
if len(res) == 0:
    print(-1)
else:
    for node in res:
        print(node)
