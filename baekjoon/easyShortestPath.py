import sys
from collections import deque
import copy

N, M = list(map(int, input().split(" ")))

board = []
for _ in range(N):
    board.append(list(map(int, sys.stdin.readline().rstrip().split(" "))))

newBoard = copy.deepcopy(board)

for y in range(N):
    for x in range(M):
        if newBoard[y][x] == 1:
            newBoard[y][x] = -1
q = deque()

directions = [[-1, 0], [0, -1], [1, 0], [0, 1]]
visited = []

startY = 0
startX = 0

for y in range(N):
    for x in range(M):
        if board[y][x] == 2:
            startY = y
            startX = x

for _ in range(N):
    visited.append([0] * M)


q.append([startY, startX, 0])
visited[startY][startX] = 1

while len(q) > 0:
    curY, curX, moveCnt = q.popleft()

    for direction in directions:
        nextY = curY + direction[0]
        nextX = curX + direction[1]

        if 0 <= nextY and nextY < N and 0 <= nextX and nextX < M:
            if visited[nextY][nextX] == 0:
                if board[nextY][nextX] == 1:
                    visited[nextY][nextX] = 1
                    q.append([nextY, nextX, moveCnt + 1])
                    newBoard[nextY][nextX] = moveCnt + 1


newBoard[startY][startX] = 0


for y in range(N):
    for x in range(M):
        if x < M - 1:
            print(newBoard[y][x], end=" ")
        else:
            print(newBoard[y][x], end="\n")
