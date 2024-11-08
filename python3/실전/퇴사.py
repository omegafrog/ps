import sys

N = int(input())

inputs = []
for _ in range(N):
    inputs.append(list(map(int, sys.stdin.readline().rstrip().split())))

mem = [0] * (N + 1)
for i in range(N):
    t, p = inputs[i]
    if i + t <= N:
        mem[i + t] = max(mem[i] + p, mem[i + t])
        for j in range(i + t, N):
            mem[j] = mem[i + t]
    else:
        mem[N] = max(mem[i], mem[N])

print(max(mem[N], mem[N - 1]))
