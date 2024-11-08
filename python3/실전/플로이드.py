import sys

INF = 987654321

N = int(input())
M = int(input())

bus = []

for _ in range(N + 1):
    bus.append([INF] * (N + 1))

for _ in range(M):
    u, v, c = list(map(int, sys.stdin.readline().rstrip().split()))
    bus[u][v] = min(bus[u][v], c)

print(bus)
for i in range(1, N + 1):
    for u in range(1, N + 1):
        for v in range(1, N + 1):
            if u == v:
                bus[u][v] = 0
                continue
            if bus[u][v] > bus[u][i] + bus[i][v]:
                bus[u][v] = bus[u][i] + bus[i][v]

for u in range(1, N + 1):
    for v in range(1, N + 1):
        if bus[u][v] < INF:
            print(bus[u][v], end=" ")
        elif bus[u][v] >= INF:
            print(0, end=" ")
    print()
