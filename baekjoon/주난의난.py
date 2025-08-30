from collections import deque

N, M = list(map(int, input().rstrip().split()))

directions = [[-1, 0], [0, -1], [1, 0], [0, 1]]

y1, x1, y2, x2 = list(map(int, input().rstrip().split()))

board = []
for _ in range(N):
    tmp = list(input())
    a = []
    for word in tmp:
        a.append(word)
    board.append(a)


print(board)
end = [y2 - 1, x2 - 1]
start = [y1 - 1, x1 - 1]

stack = deque([])

cnt = 0

board[start[0]][start[1]] = "0"

while True:
    cnt += 1
    stack.append(start)
    visited = [[0] * M for _ in range(N)]
    visited[start[0]][start[1]] = 1
    while len(stack) > 0:
        cur = stack.popleft()

        if board[cur[0]][cur[1]] == "#":
            print(cnt)
            exit(0)

        for dir in directions:
            nextY = cur[0] + dir[0]
            nextX = cur[1] + dir[1]
            print()
            for row in board:
                print(row)
            if (
                0 <= nextY
                and nextY < N
                and 0 <= nextX
                and nextX < M
                and visited[nextY][nextX] == 0
            ):
                if board[nextY][nextX] == "1":
                    board[nextY][nextX] = "0"
                elif board[nextY][nextX] == "0":
                    stack.append([nextY, nextX])
                    visited[nextY][nextX] = 1
                else:
                    stack.append([nextY, nextX])
