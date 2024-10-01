import sys
from collections import deque

N = int(input())

classes = []
for i in range(N+1):
    classes.append([0,0])
res = [0]*(N+1)

adj = []
for i in range(N+1):
    adj.append([])

indegree=[0]*(N+1)

for i in range(1,N+1):
    inputs = list(map(int, sys.stdin.readline().rstrip().split()))[:-1]
    classes[i][0] = inputs[0]

    for node in inputs[1:]:
        adj[node].append(i)
        indegree[i]+=1
    
q = deque()

for i in range(1, N+1):
    if indegree[i] == 0:
        q.append(i)
        
print(classes, indegree, adj)

while len(q)>0:
    cur = q.popleft()
    res[cur] = classes[cur][0]
    for nextNode in adj[cur]:
        indegree[nextNode]-=1
        classes[nextNode][1] = max(classes[nextNode][1], classes[cur][0])
        if indegree[nextNode] == 0:
            classes[nextNode][0]+=classes[nextNode][1]
            classes[nextNode][1] = 0
            q.append(nextNode)

print(res)