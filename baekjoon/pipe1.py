import sys

HORIZONTAL = 0
VERTICAL = 2
CROSS = 1


dirs = [[0, 1], [1, 1], [1, 0]]

N = int(input())

lines = []

for _ in range(N):
    lines.append(list(map(int, sys.stdin.readline().rstrip().split())))

init = [0, 0, 0]
mem = [[init[:] for _ in range(N)] for _ in range(N)]


mem[0][0][HORIZONTAL] = 1
mem[0][1][HORIZONTAL] = 1


for y in range(N):
    for x in range(N):
        if x == 0 and y == 0:
            continue
        for dir in range(3):
            if mem[y][x][dir] > 0:
                if dir == HORIZONTAL:
                    if x + 1 < N and lines[y][x + 1] == 0:
                        mem[y][x + 1][HORIZONTAL] += mem[y][x][dir]
                    if (
                        x + 1 < N
                        and y + 1 < N
                        and lines[y][x + 1] == 0
                        and lines[y + 1][x] == 0
                        and lines[y + 1][x + 1] == 0
                    ):
                        mem[y + 1][x + 1][CROSS] += mem[y][x][dir]
                if dir == VERTICAL:
                    if y + 1 < N and lines[y + 1][x] == 0:
                        mem[y + 1][x][VERTICAL] += mem[y][x][dir]
                    if (
                        y + 1 < N
                        and x + 1 < N
                        and lines[y][x + 1] == 0
                        and lines[y + 1][x] == 0
                        and lines[y + 1][x + 1] == 0
                    ):
                        mem[y + 1][x + 1][CROSS] += mem[y][x][dir]
                if dir == CROSS:
                    if x + 1 < N and lines[y][x + 1] == 0:
                        mem[y][x + 1][HORIZONTAL] += mem[y][x][dir]
                    if y + 1 < N and lines[y + 1][x] == 0:
                        mem[y + 1][x][VERTICAL] += mem[y][x][dir]
                    if (
                        x + 1 < N
                        and y + 1 < N
                        and lines[y + 1][x + 1] == 0
                        and lines[y][x + 1] == 0
                        and lines[y + 1][x] == 0
                    ):
                        mem[y + 1][x + 1][CROSS] += mem[y][x][dir]


# for i in range(N):
#     print(mem[i])
print(sum(mem[N - 1][N - 1]))
