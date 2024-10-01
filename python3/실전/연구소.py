## elapsed : 01 : 11 : 34
## solved

## 접근은 잘 함. visited를 매번 수행마다 초기화해야 되는데 python에서 이걸 하는 방법을 몰라서
## 시간을 많이 소요함.
## import copy
## a = []
## b = copy.deepcopy(a) 로 할 수 있음. 그냥 b= a 해버리면 같은 레퍼런스를 가리키게 됨.
## 나머지는 잘 한듯. 마지막에 벽 숫자 3개 빼야함.
## 추가적으로 벽의 위치를 정해야 할때 그냥 벽 위치 모두 배열에 넣어놓고 순서대로 3개 뽑았음.
## 예전 코드에서는 재귀적으로 3개의 벽 위치 정함. 이게 좀 더 멋있는 코드인듯...
import sys
import copy
from collections import deque


def bfs(board, visited, startY, startX, safeCnt):
    cnt = safeCnt
    q = deque()
    q.append([startY, startX])
    visited[startY][startX] = 1
    while len(q) > 0:
        cur = q.popleft()

        for direction in directions:
            nextY = cur[0] + direction[0]
            nextX = cur[1] + direction[1]

            if 0 <= nextY < len(board) and 0 <= nextX < len(board[0]):
                if visited[nextY][nextX] == 0 and board[nextY][nextX] == 0:
                    visited[nextY][nextX] = 1
                    q.append([nextY, nextX])
                    cnt = cnt - 1
    return cnt


directions = [[0, -1], [0, 1], [1, 0], [-1, 0]]
N, M = map(int, sys.stdin.readline().rstrip().split())

ADDED_WALL = 3

board = []

virus = []
visited = []
canWall = []
safeCnt = 0

for y in range(N):
    visited.append([0] * M)

for y in range(N):
    board.append(list(map(int, sys.stdin.readline().rstrip().split())))


for y in range(N):
    for x in range(M):
        if board[y][x] == 2:
            virus.append([y, x])
        if board[y][x] == 0:
            safeCnt += 1
            canWall.append([y, x])

res = -1
for p1 in range(len(canWall)):
    for p2 in range(p1 + 1, len(canWall)):
        for p3 in range(p2 + 1, len(canWall)):
            y1, x1 = canWall[p1]
            y2, x2 = canWall[p2]
            y3, x3 = canWall[p3]
            board[y1][x1] = ADDED_WALL
            board[y2][x2] = ADDED_WALL
            board[y3][x3] = ADDED_WALL
            cnt = safeCnt
            tmpVisited = copy.deepcopy(visited)

            for v in virus:
                cnt = bfs(board, tmpVisited, v[0], v[1], cnt)
            # print(y1, x1, y2, x2, y3, x3, cnt)
            res = max(res, cnt)
            board[y1][x1] = 0
            board[y2][x2] = 0
            board[y3][x3] = 0
print(res - 3)
