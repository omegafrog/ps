# 국경선을 공유하는 두 나라의 인구 차이가 L 이상 R 이하면 국경선을 하루동안 연다
# 국경선이 모두 열리면 이동 시작
# 모든 이동할 수 있는 칸의 합을 연합이라고 한다.
# 연합의 각 칸의 인구수는 연합 인구수 / 연합 칸 개수
# 연합 해체 후 국경선을 닫음.
# 1행 1열부터 for문으로 모두 순회하면서 인구 조건에 맞게 현재 칸에서 bfs 시작 -> visited 배열 공유해야됨
# 마지막 칸까지 다 방문을 끝나면 bfs한 횟수를 반환

import sys
from collections import deque
import copy


def bfs(y, x, board, visited):
    county = [[y, x]]
    totalPop = board[y][x]
    q = deque()
    q.append([y, x])
    visited[y][x] = 1

    while q:
        curY, curX = q.popleft()
        for direction in range(4):
            nextY = curY + dy[direction]
            nextX = curX + dx[direction]

            if 0 <= nextY and nextY < N and 0 <= nextX and nextX < N:
                diff = abs(board[curY][curX] - board[nextY][nextX])
                if visited[nextY][nextX] == 0 and L <= diff and diff <= R:
                    visited[nextY][nextX] = 1
                    county.append([nextY, nextX])
                    totalPop = totalPop + board[nextY][nextX]
                    q.append([nextY, nextX])

    countyPop = totalPop // len(county)
    for point in county:
        board[point[0]][point[1]] = countyPop
    return len(county)


N, L, R = list(map(int, sys.stdin.readline().rstrip().split()))
dy = [-1, 0, 1, 0]
dx = [0, -1, 0, 1]

board = []
visited = []
for _ in range(N):
    board.append(list(map(int, sys.stdin.readline().rstrip().split())))
    visited.append([0] * N)

# print(board)


bfsCnt = 0

while True:
    copiedVisited = copy.deepcopy(visited)
    cntDiff = 0
    flag = True
    for y in range(N):
        for x in range(N):
            if copiedVisited[y][x] == 0:
                changedCnt = bfs(y, x, board, copiedVisited)
                # print(y, x)
                # for i in range(N):
                #     print(board[i])
                # for i in range(N):
                #     print(copiedVisited[i])
                # print(y, x, changedCnt)
                if changedCnt > 1:
                    flag = False

    if flag:
        break
    else:
        bfsCnt += 1
    # print(board)

print(bfsCnt)
