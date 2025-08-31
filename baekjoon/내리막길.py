import sys

sys.setrecursionlimit(500 * 500 + 10)
INF = 987654321

M, N = list(map(int, input().rstrip().split()))


board = []

for _ in range(M):
    board.append(list(map(int, sys.stdin.readline().rstrip().split())))


directions = [[-1, 0], [0, -1], [1, 0], [0, 1]]

s = []
s.append([0, 0])
res = 0

dist = [[INF] * (N) for row in range(M)]


def bfs(start, dist):
    curY, curX = start
    if curY == M - 1 and curX == N - 1:
        return 1
    res = 0
    for i in range(4):
        dir = directions[i]
        nextY = curY + dir[0]
        nextX = curX + dir[1]
        if 0 <= nextY and nextY < M and 0 <= nextX and nextX < N:
            if board[nextY][nextX] < board[curY][curX]:
                if dist[nextY][nextX] == INF:
                    dist[nextY][nextX] = bfs([nextY, nextX], dist)
                res += dist[nextY][nextX]
    dist[curY][curX] = res
    return res


res = 0

res = bfs([0, 0], dist)
print(res)

# for row in dist:
#     print(row)
