import sys
from collections import deque

def Find(parent, x):
    if parent[x]!=x:
        return Find(parent, parent[x])
    return x

def Union(parent, a,b):
    rootA = Find(parent, a)
    rootB = Find(parent,b)
    if rootA>rootB:
        parent[rootA] =rootB 
    else:
        parent[rootB] = rootA


[N,M] = list(map(int, sys.stdin.readline().rstrip().split()))

edges = []
parent = [0]*(N+1)
for i in range(N+1):
    parent[i] = i

for i in range(M):
    edges.append(list(map(int, sys.stdin.readline().rstrip().split())))
    

edges = deque(sorted(edges, key=lambda edge:edge[2]))
print(edges)
totalCost = 0
biggest = -1

while len(edges)>0:
    [a,b,t] = edges.popleft()
    rootA = Find(parent, a)
    rootB = Find(parent, b)
    if rootA == rootB: continue
    Union(parent, a, b)
    print(a,b)
    totalCost+=t
    biggest = max(biggest, t)
print(biggest)
print(totalCost-biggest)


    

    

