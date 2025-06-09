from sys import stdin


C, N = list(map(int, stdin.readline().rstrip().split()))

dicts = []
for _ in range(N):
    cost, n = list(map(int, stdin.readline().rstrip().split()))
    dicts.append([cost, n])


mem = [99999999999] * (C + 101)

mem[0] = 0


def dp(dicts, mem):
    # if c <= 0:
    #     return 0
    # res = mem[c]
    # if res != 987654321:
    #     return res
    # cand = 987654321
    # for k in dicts.keys():
    #     cand = min(cand, dp(c - dicts[k], dicts, mem) + k)
    #
    # mem[c] = cand
    # return cand
    for i in range(1, C + 100):
        cand = 987654321
        for cost, num in dicts:
            if i - num < 0:
                continue
            cand = min(cand, mem[i - num] + cost)
        mem[i] = cand


res = dp(dicts, mem)
minRes = 987654321
for i in range(C, C + 100):
    minRes = min(minRes, mem[i])
print(minRes)
