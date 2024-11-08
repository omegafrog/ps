import sys

N = int(input())
inputs = []
mem = []
for i in range(N):
    tmp = list(map(int, sys.stdin.readline().rstrip().split()))
    inputs.append(tmp)
    mem.append([0] * (i + 1))

mem[0][0] = inputs[0][0]

for y in range(1, N):
    for x in range(y + 1):
        left = -1
        right = -1
        if x < len(mem[y]) - 1:
            right = mem[y - 1][x]
        if x > 0:
            left = mem[y - 1][x - 1]
        print(right, left)
        mem[y][x] = max(left, right) + inputs[y][x]

res = -1
print(mem)
for i in range(N):
    res = max(res, mem[N - 1][i])
print(res)
