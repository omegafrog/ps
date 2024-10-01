import sys
from collections import deque

APPLE = 1
Y = 0
X = 1

def turn(direction, curDirection):
    if direction == 'L':
        return (curDirection-1+4)%4
    else:
        return (curDirection+1+4)%4

def doGame():
    N = int(input())
    K = int(input())

    grid = []
    for _ in range(N+1):
        grid.append([0]*(N+1))


    for _ in range(K):
        [y,x] = list(map(int, sys.stdin.readline().rstrip().split()))
        grid[y][x]= APPLE

    curves = []
    L = int(input())
    for _ in range(L):
        [time,direction] = list(sys.stdin.readline().rstrip().split())
        curves.append([int(time), direction])

    directions = [[0,1],[1,0],[0,-1],[-1,0]]
    curDirection = 0
    head = [1,1]

    snake = deque()
    snake.append(head)

    clock = 0
    # for y in grid:
    #     print(y)  
    while True:
        head = snake[-1]
        # print(snake, head)
        
        nextY = head[Y]+directions[curDirection][Y]
        nextX = head[X]+directions[curDirection][X]
        clock+=1
        if nextY <= 0 or nextY > N or nextX <= 0 or nextX > N:
            return clock
        if [nextY,nextX] in snake:
            return clock
        
        
        if grid[nextY][nextX] == APPLE:
            grid[nextY][nextX] = 0
        else:
            snake.popleft()
        
        snake.append([nextY,nextX])
        for curve in curves:
            if curve[0] == clock:
                curDirection = turn(curve[1],curDirection)

print(doGame())

