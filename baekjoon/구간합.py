import sys

sumArr = []
N, M = list(map(int, sys.stdin.readline().rstrip().split()))

for _ in range(N + 1):
    sumArr.append([0] * (N + 1))


data = []
for i in range(N):
    data.append(list(map(int, sys.stdin.readline().rstrip().split())))


sumArr[1][1] = data[0][0]
ySum = 0
xSum = 0
for y in range(1, N + 1):
    sumArr[y][1] = ySum + data[y - 1][0]
for x in range(1, N + 1):
    sumArr[1][x] = xSum + data[0][x - 1]


for y in range(2, N + 1):
    for x in range(2, N + 1):
        sumArr[y][x] = (
            sumArr[y - 1][x]
            + sumArr[y][x - 1]
            - sumArr[y - 1][x - 1]
            + data[y - 1][x - 1]
        )

print(sumArr)

for _ in range(M):
    y1, x1, y2, x2 = list(map(int, sys.stdin.readline().rstrip().split()))

    res = 0
    if y1 > 1 and x1 > 1:
        a = sumArr[y1 - 1][x1 - 1]
        b = sumArr[y2][x1 - 1]
        c = sumArr[y1 - 1][x2]
        d = sumArr[y2][x2]
        res = d - c - b + a
    elif y1 == 1:
        b = sumArr[y2][x1 - 1]
        d = sumArr[y2][x2]
        res = d - b
    elif x1 == 1:
        d = sumArr[y2][x2]
        b = sumArr[y1 - 1][x2]
        res = d - b
    else:
        a = sumArr[1][1]
        b = sumArr[y2][1]
        c = sumArr[1][x2]
        d = sumArr[y2][x2]
        res = d - c - b + a
    print(res)
