import sys

def Find(parent, x):
    if parent[x]!=x:
        return Find(parent, parent[x])
    return parent[x]

def Union(parent, a, b):
    rootA = Find(parent, a)
    rootB = Find(parent, b)
    
    if rootA < rootB:
        parent[rootB] = rootA
    else:
        parent[rootA] = rootB
    

[N,M] = list(map(int, sys.stdin.readline().rstrip().split()))

parent = [0]*(N+1)
for i in range(N+1):
    parent[i] = i

for i in range(M):
    [operator, oprand1, oprand2] = list(map(int, sys.stdin.readline().rstrip().split()))
    if operator == 0:
        Union(parent, oprand1, oprand2)
    else:
        if Find(parent, oprand1) == Find(parent, oprand2):
            print("YES")
        else: print("NO")