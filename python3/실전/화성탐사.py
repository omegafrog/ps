import sys
import heapq


INF = 987654321


adjX = [-1, 0, 1, 0]
adjY = [0, -1, 0, 1]


def execute():
    N = int(input())
    space = []
    visited = []
    res = []
    for _ in range(N):
        visited.append([False] * (N))
        res.append([INF] * (N))

    pq = []

    for _ in range(N):
        space.append(list(map(int, sys.stdin.readline().rstrip().split())))

    visited[0][0] = True
    heapq.heappush(pq, [space[0][0], 0, 0])
    res[0][0] = space[0][0]

    while pq:
        v, y, x = heapq.heappop(pq)
        for direction in range(4):
            nextY = y + adjY[direction]
            nextX = x + adjX[direction]
            if 0 <= nextX and nextX < N and 0 <= nextY and nextY < N:
                if res[nextY][nextX] != INF:
                    continue
                res[nextY][nextX] = min(res[nextY][nextX], v + space[nextY][nextX])
                visited[nextY][nextX] = True
                heapq.heappush(pq, [res[nextY][nextX], nextY, nextX])

    print(res)
    return res[N - 1][N - 1]


T = int(input())

for _ in range(T):
    print(execute())
