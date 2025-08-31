from collections import deque
import heapq

N = int(input())

board = []
for _ in range(N):
    board.append(list(map(int, input().rstrip().split())))

start = []

for y in range(N):
    for x in range(N):
        if board[y][x] == 9:
            start = [y, x]
            break


size = 2
cnt = 0
directions = [[-1, 0], [0, -1], [0, 1], [1, 0]]

time = 0

h = []

for y in range(N):
    for x in range(N):
        if board[y][x] > 0 and board[y][x] <= 6 and board[y][x] < size:
            heapq.heappush(h, (y, x))


def move(board, start, size):
    visited = [[0] * (N) for _ in range(N)]
    q = deque()
    q.append([start[0], start[1], 0])
    visited[start[0]][start[1]] = 1
    board[start[0]][start[1]] = 0

    time = 1
    tmp = []
    while len(q) > 0:
        # print(tmp, q)
        curY, curX, curTime = q.popleft()
        if time < curTime:
            if len(tmp) > 0:
                tmp.sort(key=lambda x: (x[0], x[1]))
                board[tmp[0][0]][tmp[0][1]] = 0
                return time, tmp[0]
            else:
                time = curTime
                tmp = []
        if (
            board[curY][curX] > 0
            and board[curY][curX] <= 6
            and size > board[curY][curX]
        ):
            tmp.append([curY, curX])
        for dir in directions:
            nextY = curY + dir[0]
            nextX = curX + dir[1]
            if (
                0 <= nextY
                and nextY < N
                and 0 <= nextX
                and nextX < N
                and visited[nextY][nextX] == 0
                and board[nextY][nextX] <= size
            ):
                q.append([nextY, nextX, curTime + 1])
                visited[nextY][nextX] = 1

    if len(tmp) > 0:
        tmp.sort(key=lambda x: (x[0], x[1]))
        board[tmp[0][0]][tmp[0][1]] = 0
        return time, tmp[0]
    else:
        return -1, [0, 0]


while True:
    res, next = move(board, start, size)
    # print(res, next)
    if res == -1:
        break
    else:
        start = next
        time += res
        cnt += 1
        if cnt == size:
            cnt = 0
            size += 1
        # print(start, size, time)
        # for row in board:
        #     print(row)

print(time)
