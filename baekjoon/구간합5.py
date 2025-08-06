import sys

n, m = list(map(int, input().rstrip().split()))

board = []
sumboard = [[0] * (n) for _ in range(n)]
for _ in range(n):
    board.append(list(map(int, sys.stdin.readline().rstrip().split())))

sumboard[0][0] = board[0][0]

sum = 0
for y in range(n):
    sum += board[y][0]
    sumboard[y][0] = sum

sum = 0
for x in range(n):
    sum += board[0][x]
    sumboard[0][x] = sum

for y in range(1, n):
    for x in range(1, n):
        sumboard[y][x] = (
            sumboard[y][x - 1]
            + sumboard[y - 1][x]
            - sumboard[y - 1][x - 1]
            + board[y][x]
        )

# print(sumboard)


def allsum(y1, x1, y2, x2, sumboard):
    if y1 == 0 and x1 == 0:
        return sumboard[y2][x2]
    elif y1 == 0:
        return sumboard[y2][x2] - sumboard[y2][x1 - 1]
    elif x1 == 0:
        return sumboard[y2][x2] - sumboard[y1 - 1][x2]
    else:
        return (
            sumboard[y2][x2]
            - sumboard[y1 - 1][x2]
            - sumboard[y2][x1 - 1]
            + sumboard[y1 - 1][x1 - 1]
        )


for _ in range(m):
    y1, x1, y2, x2 = list(map(int, sys.stdin.readline().rstrip().split()))
    y1 -= 1
    x1 -= 1
    y2 -= 1
    x2 -= 1
    print(allsum(y1, x1, y2, x2, sumboard))
