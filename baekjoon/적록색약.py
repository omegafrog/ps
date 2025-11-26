import sys
from collections import deque

directions = [[-1,0],[0,1],[1,0],[0,-1]]

N = int(input())

pixels = []

for _ in range(N):
    pixels.append(list(sys.stdin.readline().rstrip()))

visited = [[0]*(N) for _ in range(N)]

Rcnt = Gcnt = Bcnt = 0

def bfs(startY, startX, board, visited):
    q = deque()
    color = board[startY][startX]

    q.append([startY, startX])
    visited[startY][startX] = 1

    while q:
        startY, startX = q.popleft()
        for dir in directions:
            nextY = startY + dir[0]
            nextX =  startX + dir[1]
            if 0<= nextY and nextY < N and 0<=nextX and nextX < N:
                if visited[nextY][nextX]==0 and board[nextY][nextX] == color:
                    visited[nextY][nextX] = 1
                    q.append([nextY, nextX])
    return color

# 정상인
for y in range(N):
    for x in range(N):
            if visited[y][x] == 0:
                color = bfs(y, x, pixels, visited)
                if color == 'B':
                    Bcnt+=1
                elif color == 'R':
                    Rcnt+=1
                else:
                    Gcnt+=1
print(Bcnt+Gcnt+Rcnt)

def bfs_sameRG(startY, startX, board, visited):
    q = deque()
    color = board[startY][startX]

    q.append([startY, startX])
    visited[startY][startX] = 1

    while q:
        startY, startX = q.popleft()
        for dir in directions:
            nextY = startY + dir[0]
            nextX =  startX + dir[1]
            if 0<= nextY and nextY < N and 0<=nextX and nextX < N:
                if visited[nextY][nextX]==0:
                    if color == 'R' or color == 'G':
                        if board[nextY][nextX] == 'R' or board[nextY][nextX] == 'G':
                            visited[nextY][nextX] = 1
                            q.append([nextY, nextX])
                    else:
                        if board[nextY][nextX] == color:
                            visited[nextY][nextX] = 1
                            q.append([nextY, nextX])
    return color

# 적녹색맹
visited = [[0]*(N) for _ in range(N)]
Bcnt = 0
Rcnt = 0
Gcnt = 0
for y in range(N):
    for x in range(N):
        if visited[y][x] == 0:
            color = bfs_sameRG(y, x, pixels, visited)
            if color == 'B':
                Bcnt+=1
            else:
                Rcnt+=1
print(Bcnt+Rcnt)