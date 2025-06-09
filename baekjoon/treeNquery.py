import sys

N, R, Q = list(map(int, sys.stdin.readline().rstrip().split()))
edges = []
mem = [-1] * (N + 1)


def countNode(root, mem, visited):
    count = 0
    if mem[root] != -1:
        return mem[root]
    for v in edges[root]:
        if visited[v] == 0:
            visited[v] = 1
            count += countNode(v, mem, visited)
    mem[root] = count
    return mem[root] + 1


for i in range(N + 1):
    edges.append([])

for _ in range(N - 1):
    u, v = list(map(int, sys.stdin.readline().rstrip().split()))
    edges[u].append(v)
    edges[v].append(u)

print(edges)
for _ in range(Q):
    root = int(input())
    visited = [0] * (N + 1)
    visited[root] = 1
    res = countNode(root, mem, visited)
    print(res - 1)
