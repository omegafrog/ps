import sys


def find(parent, x):
    tmp = []
    while parent[x] != x:
        tmp.append(x)
        x = parent[x]

    for a in tmp:
        parent[a] = x
    return parent[x]


def union(rank, parent, x, y):
    rootX = find(parent, x)
    rootY = find(parent, y)

    if rank[rootX] < rank[rootY]:
        parent[rootY] = rootX
    elif rank[rootX] > rank[rootY]:
        parent[rootX] = rootY
    else:
        parent[rootY] = rootX
        rank[rootX] += 1


V, E = list(map(int, sys.stdin.readline().rstrip().split()))

parents = []
edges = []
rank = []
for i in range(V + 1):
    parents.append(i)
    rank.append(1)

for _ in range(E):
    a, b, c = list(map(int, sys.stdin.readline().rstrip().split()))
    edges.append([a, b, c])


edges.sort(key=lambda x: x[2])

res = 0

for edge in edges:
    a = edge[0]
    b = edge[1]
    c = edge[2]

    rootA = find(parents, a)
    rootB = find(parents, b)
    if rootA != rootB:
        res += c
        union(rank, parents, rootA, rootB)

print(res)
