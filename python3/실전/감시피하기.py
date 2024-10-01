## 41:55 / 60:00
## 풀음

## recursive에서 return하는 거를 대가리가 잘 안굴러감;
import sys
import copy

N = int(input())

dy = [-1, 0, 1, 0]
dx = [0, -1, 0, 1]

board = []

s = []


def dfs(board, s):
    while s:
        curY, curX, direction = s.pop()
        if board[curY][curX] == "O":
            continue
        if board[curY][curX] == "S":
            return "NO"

        nextY = curY + dy[direction]
        nextX = curX + dx[direction]
        if 0 <= nextY < N and 0 <= nextX < N:
            if board[nextY][nextX] == "S":
                return "NO"
            if board[nextY][nextX] == "O":
                continue
            else:
                s.append([nextY, nextX, direction])

    return "YES"


def recursiveWall(wallCnt, board, s):
    res = "NO"
    if wallCnt == 3:
        copiedS = copy.deepcopy(s)
        return dfs(board, copiedS)
    else:
        for y in range(N):
            for x in range(N):
                if board[y][x] == "X":
                    board[y][x] = "O"
                    res = recursiveWall(wallCnt + 1, board, s)
                    if res == "YES":
                        return res
                    board[y][x] = "X"
    return res


for y in range(N):
    board.append(sys.stdin.readline().rstrip().split())
    for x in range(N):
        if board[y][x] == "T":
            for direction in range(4):
                if 0 <= y + dy[direction] < N and 0 <= x + dx[direction] < N:
                    s.append([y + dy[direction], x + dx[direction], direction])
# print(s)

print(recursiveWall(0, board, s))
