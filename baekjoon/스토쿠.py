import sys
import copy

zeroCells = []
grid = []
for i in range(9):
    tmp = []
    inputStr = input()
    for j in range(9):
        tmp.append(int(inputStr[j]))
    grid.append(tmp)

print(grid)


for y in range(9):
    for x in range(9):
        if grid[y][x] == 0:
            zeroCells.append([y, x])


def solve(zeroCells, idx):
    if len(zeroCells) == idx:
        for i in range(9):
            print(grid[i])
        exit(0)

    y, x = zeroCells[idx]

    print("x: {0}, y: {1}".format(x, y))
    for i in range(9):
        print(grid[i])

    valid = set()
    for hor in range(9):
        if grid[y][hor] != 0:
            valid.add(grid[y][hor])
    for ver in range(9):
        if grid[ver][x] != 0:
            valid.add(grid[ver][x])

    startY = y // 3 * 3
    startX = x // 3 * 3
    print("startY :{0}, startX: {1}".format(startY, startX))

    for squareY in range(startY, startY + 3):
        for squareX in range(startX, startX + 3):
            if grid[squareY][squareX] != 0:
                valid.add(grid[squareY][squareX])

    print(valid)

    if len(valid) == 9:
        return

    for i in range(1, 10):
        if i not in valid:
            grid[y][x] = i
            solve(zeroCells, idx + 1)


solve(zeroCells, 0)
