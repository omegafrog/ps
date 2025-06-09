import sys

N, M = list(map(int, input().split(" ")))

board = []
sumBoard = []

for _ in range(N):
    board.append(list(map(int, sys.stdin.readline().rstrip().split(" "))))
    board.append([0] * N)

sumVal = 0

for y in range(N):
    for x in range(N):
        sumBoard[y][x] = sumVal + board[y][x]

for i in range(M):
    startY, startX, endY, endX = list(
        map(int, sys.stdin.readline().rstrip().split(" "))
    )
