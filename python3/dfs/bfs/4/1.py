import sys
from collections import deque
[N,M] = list(map(int, sys.stdin.readline().rstrip().split()))

field = []
visited = []
for y in range(N):
    visited.append([])
    for x in range(M):
        visited[y].append(0)

for i in range(N):
    field.append(list(map(int, input())))

res = 0

q = deque()
q.append([0,0])
visited[0][0] = 1

directions = [[-1,0],[0,1],[1,0],[0,-1]]

while len(q)>0:
    cur = q.popleft()
    print(cur, N, M)
    if cur[0] == N-1 and cur[1] == M-1:
        break
    for direction in directions:
        nextPos = [cur[0]+direction[0], cur[1]+direction[1]]
        if 0<=nextPos[0] and nextPos[0] < N and 0<=nextPos[1] and nextPos[1]<M:
            if field[nextPos[0]][nextPos[1]]==1 and visited[nextPos[0]][nextPos[1]]==0:
                q.append(nextPos)
                visited[nextPos[0]][nextPos[1]] = 1
                field[nextPos[0]][nextPos[1]] = field[cur[0]][cur[1]]+1
                
                

print(field[N-1][M-1])
