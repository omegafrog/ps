import copy

N, M = list(map(int, input().rstrip().split()))


RIGHT = 0
UP = 1
LEFT = 2
DOWN = 3

board = []
directions = [[0, 1], [-1, 0], [0, -1], [1, 0]]

for _ in range(N):
    board.append(list(map(int, input().rstrip().split())))

cctvs = []

for y in range(N):
    for x in range(M):
        if board[y][x] > 0 and board[y][x] < 6:
            cctvs.append([y, x, board[y][x]])


def observe(board, y, x, dir):
    cnt = 0
    curY = y
    curX = x
    while 0 <= curY and curY < N and 0 <= curX and curX < M and board[curY][curX] != 6:
        if board[curY][curX] == "#":
            curY += dir[0]
            curX += dir[1]
            continue
        elif board[curY][curX] > 0 and board[curY][curX] < 6:
            curY += dir[0]
            curX += dir[1]
            continue
        board[curY][curX] = "#"
        cnt += 1
        curY += dir[0]
        curX += dir[1]
    return cnt


def backTracking(board, cctvs, idx):
    cnt = 0
    if idx == len(cctvs):
        for y in range(N):
            for x in range(M):
                if board[y][x] == 0:
                    cnt += 1
        return cnt

    res = 987654321
    y, x, cctvType = cctvs[idx]
    for i in range(len(directions)):
        if cctvType == 1:
            tmp = copy.deepcopy(board)
            observe(tmp, y, x, directions[i])
            res = min(
                res,
                backTracking(tmp, cctvs, idx + 1),
            )

        elif cctvType == 2:
            tmp = copy.deepcopy(board)
            observe(tmp, y, x, directions[i])
            observe(tmp, y, x, directions[(i + 2) % 4])

            res = min(res, backTracking(tmp, cctvs, idx + 1))
        elif cctvType == 3:
            tmp = copy.deepcopy(board)
            observe(tmp, y, x, directions[(i + 1) % 4])
            observe(tmp, y, x, directions[(i + 2) % 4])
            res = min(res, backTracking(tmp, cctvs, idx + 1))
        elif cctvType == 4:
            tmp = copy.deepcopy(board)
            observe(tmp, y, x, directions[i])
            observe(tmp, y, x, directions[(i + 1) % 4])
            observe(tmp, y, x, directions[(i + 2) % 4])
            res = min(res, backTracking(tmp, cctvs, idx + 1))
        elif cctvType == 5:
            tmp = copy.deepcopy(board)
            observe(tmp, y, x, directions[i])
            observe(tmp, y, x, directions[(i + 1) % 4])
            observe(tmp, y, x, directions[(i + 2) % 4])
            observe(tmp, y, x, directions[(i + 3) % 4])
            res = min(res, backTracking(tmp, cctvs, idx + 1))
    return res


res = backTracking(board, cctvs, 0)
print(res)
