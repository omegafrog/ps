import sys
n = int(input())

p = list(map(int, sys.stdin.readline().rstrip().split(" ")))

mem = [987654321]*(n+1)
mem[0] = 0


for i in range(1, n+1):
    for j in range(1, i+1):
        mem[i] = min(mem[i], mem[i-j]+p[j-1])

print(mem[n])
