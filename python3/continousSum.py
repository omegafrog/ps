import sys

n = int(input())


a = list(map(int, sys.stdin.readline().rstrip().split(" ")))

mem = [0]*len(a)

mem[0] = a[0]

for i in range(1, len(a)):
    mem[i] = a[i] + (mem[i-1] if mem[i-1] > 0 else 0)

ret = -987654321

for i in mem:
    ret = max(i, ret)

print(ret)
