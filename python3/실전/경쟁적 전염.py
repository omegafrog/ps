## 01:14:31
## 풀지못함

## " 작은 숫자의 균부터 전염된다 -> 큐 초기화 시에  작은 숫자 균부터 먼저 넣으면 된다."
## 작은 균이 먼저 전염되니까 큐에 먼저 넣어서 bfs적용
## 인접 노드 큐에 넣을 때 이미 board에 변화가 적용되어 있는 상태이고
## 큐에서 팝 한 시점에는 이미 board에 변화가 일어나 있으므로 팝 한 시점에 t를 비교해서 시간을 측정함.
## 시발


import sys
from collections import deque


directions = [[-1, 0], [0, -1], [1, 0], [0, 1]]

N, K = map(int, sys.stdin.readline().rstrip().split())

board = []

for _ in range(N):
    board.append(list(map(int, sys.stdin.readline().rstrip().split())))


S, X, Y = map(int, sys.stdin.readline().strip().split())

data = []

for y in range(N):
    for x in range(N):
        if board[y][x] > 0:
            data.append([y, x, 0, board[y][x]])

data.sort(key=lambda x: x[3])
q = deque(data)


# print(q)
while len(q) > 0:
    curY, curX, t, i = q.popleft()
    if t == S:
        break
    for direction in directions:
        nextY = curY + direction[0]
        nextX = curX + direction[1]
        if 0 <= nextY < N and 0 <= nextX < N:
            if board[nextY][nextX] == 0:
                board[nextY][nextX] = i
                q.append([nextY, nextX, t + 1, i])

print(board[X - 1][Y - 1])
