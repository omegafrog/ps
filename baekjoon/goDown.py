import sys

N = int(input())
mem2 = []
for y in range(N):
    line = list(map(int, sys.stdin.readline().rstrip().split()))
    if y == 0:
        mem2 = [
            [
                [line[0], line[0]],
                [line[1], line[1]],
                [line[2], line[2]],
            ],
            [[987654321, -1], [987654321, -1], [987654321, -1]],
        ]
    else:
        for x in range(3):
            if x == 0:
                mem2[1][x][0] = min(mem2[0][0][0], mem2[0][1][0]) + line[x]
                mem2[1][x][1] = max(mem2[0][0][1], mem2[0][1][1]) + line[x]

            elif x == 1:
                mem2[1][x][0] = (
                    min(mem2[1 - 1][0][0], min(mem2[1 - 1][1][0], mem2[1 - 1][2][0]))
                    + line[x]
                )
                mem2[1][x][1] = (
                    max(mem2[1 - 1][0][1], max(mem2[1 - 1][1][1], mem2[1 - 1][2][1]))
                    + line[x]
                )
            else:
                mem2[1][x][0] = min(mem2[1 - 1][1][0], mem2[1 - 1][2][0]) + line[x]
                mem2[1][x][1] = max(mem2[1 - 1][1][1], mem2[1 - 1][2][1]) + line[x]
        mem2[0] = mem2[1]
        mem2[1] = [[987654321, -1], [987654321, -1], [987654321, -1]]

print(
    max(mem2[0][0][1], max(mem2[0][1][1], mem2[0][2][1])),
    min(mem2[0][0][0], min(mem2[0][1][0], mem2[0][2][0])),
)
