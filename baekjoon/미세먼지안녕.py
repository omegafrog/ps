import sys

adj = [[-1, 0], [0, -1], [1, 0], [0, 1]]

R, C, T = list(map(int, input().rstrip().split()))

board = []
dusts = []

for _ in range(R):
    board.append(list(map(int, sys.stdin.readline().rstrip().split())))

air = []

for y in range(R):
    for x in range(C):
        if board[y][x] == -1:
            air.append([y, x])
        if board[y][x] > 0:
            dusts.append([y, x])


air.sort(key=lambda x: x[0])


def rotate():
    for y in range(air[0][0] - 1, 0, -1):
        board[y][air[0][1]] = board[y - 1][air[0][1]]
    for x in range(0, C - 1):
        board[0][x] = board[0][x + 1]
    for y in range(0, air[0][0]):
        board[y][C - 1] = board[y + 1][C - 1]
    for x in range(C - 1, 0, -1):
        board[air[0][0]][x] = board[air[0][0]][x - 1]
    board[air[0][0]][air[0][1] + 1] = 0

    for y in range(air[1][0] + 1, R - 1):
        board[y][0] = board[y + 1][0]
    for x in range(0, C - 1):
        board[R - 1][x] = board[R - 1][x + 1]
    for y in range(R - 1, air[1][0], -1):
        board[y][C - 1] = board[y - 1][C - 1]
    for x in range(C - 1, 1, -1):
        board[air[1][0]][x] = board[air[1][0]][x - 1]
    board[air[1][0]][1] = 0


for _ in range(T):
    tmp = [[0] * (C) for _ in range(R)]

    for y in range(R):
        for x in range(C):
            if board[y][x] > 0:
                quantity = board[y][x]
                valueToAdd = quantity // 5
                for dy, dx in adj:
                    nextY = y + dy
                    nextX = x + dx
                    if 0 <= nextY and nextY < R and 0 <= nextX and nextX < C:
                        if board[nextY][nextX] == -1:
                            continue
                        tmp[y][x] -= valueToAdd
                        tmp[nextY][nextX] += valueToAdd
    for y in range(R):
        for x in range(C):
            board[y][x] += tmp[y][x]
    rotate()


res = 0
for row in board:
    for cell in row:
        if cell > 0:
            res += cell
print(res)
