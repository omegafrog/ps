import sys

T = int(input())

for _ in range(T):
    N, M = list(map(int, sys.stdin.readline().rstrip().split()))
    tmp = list(map(int, sys.stdin.readline().rstrip().split()))
    mine = []
    mem = []
    idx = 0
    for _ in range(N):
        mine.append(tmp[idx : idx + M])
        mem.append([0] * M)
        idx += M
    for y in range(N):
        mem[y][0] = mine[y][0]

    for x in range(1, M):
        for y in range(N):
            cand1 = mem[y][x - 1] + mine[y][x]
            cand2 = 0
            cand3 = 0
            if y > 0:
                cand2 = mem[y - 1][x - 1] + mine[y][x]
            if y < N - 1:
                cand3 = mem[y + 1][x - 1] + mine[y][x]

            mem[y][x] = max(cand1, cand2, cand3)

    res = -1
    for y in range(N):
        res = max(res, mem[y][M - 1])
    print(res)
