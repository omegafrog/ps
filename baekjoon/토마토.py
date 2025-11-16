import sys 
from collections import deque
M, N, H = list(map(int, sys.stdin.readline().rstrip().split()))

box = []
for _ in range(H):
    tmp =[]
    for _ in range(N):
        tmp.append(list(map(int, sys.stdin.readline().rstrip().split())))
    box.append(tmp)

# [z,y,x]
directions = [[-1,0,0],[1,0,0],[0,-1,0],[0,1,0],[0,0,1],[0,0,-1]]

q = deque()

cnt = 0


for z in range(H):
    for y in range(N):
        for x in range(M):
            if box[z][y][x] == 1:
                q.append([0, z,y,x])
            if box[z][y][x] == 0:
                cnt+=1
if cnt == 0:
    print(0)
    exit()

# print(cnt)
lastDate = 0
while q:
    curDate, curZ, curY, curX = q.popleft()
    lastDate = max(curDate, lastDate)
    for direction in directions:
        nextZ = curZ+direction[0]
        nextY = curY+direction[1]
        nextX = curX+direction[2]        

        if 0<= nextZ and nextZ < H and 0 <= nextY and nextY < N and 0 <= nextX and nextX < M:
            if box[nextZ][nextY][nextX] == 0:
                box[nextZ][nextY][nextX] = 1
                q.append([curDate+1, nextZ, nextY, nextX])
                cnt-=1

# print(box)
# print(cnt)
if cnt >0:
    print(-1)
else:
    print(lastDate)