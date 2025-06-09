import sys

sumArr = []

N, M = map(int, sys.stdin.readline().rstrip().split(" "))

inputArr = list(map(int, sys.stdin.readline().rstrip().split(" ")))

sum = 0

for num in inputArr:
    sum += num
    sumArr.append(sum)

for _ in range(M):
    i, j = list(map(int, sys.stdin.readline().rstrip().split(" ")))
    i -= 2
    j -= 1
    if i < 0:
        print(sumArr[j])
    else:
        print(sumArr[j] - sumArr[i])
