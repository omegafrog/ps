N, M = list(map(int, input().rstrip().split()))

arr = []

for i in range(N):
    arr.append(i)

res = [0] * (M)
idx = 0


def getNext(idx, start):
    if idx >= M:
        for num in res:
            print(num, end=" ")
        print()
        return
    for i in range(start, N + 1):
        res[idx] = i
        getNext(idx + 1, i)


getNext(idx, 1)
