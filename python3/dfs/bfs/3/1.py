# start: 16:31
import sys

[N,M] = list(map(int, sys.stdin.readline().rstrip().split()))

field = []
for i in range(N):
    field.append(list(map(int, input())))
res = 0

directions = [[-1,0],[0,1],[1,0],[0,-1]]

for y in range(N):
    for x in range(M):
        if field[y][x] == 0:
            stack = []
            stack.append([y,x])
            while len(stack)>0:
                curPos = stack.pop()
                for direction in directions:
                    nextPos = [curPos[0]+direction[0], curPos[1]+direction[1]]
                    if 0<= nextPos[0] and nextPos[0] < N and 0<= nextPos[1] and nextPos[1]<M:
                        if field[nextPos[0]][nextPos[1]] == 0:
                            field[nextPos[0]][nextPos[1]] = 2
                            stack.append(nextPos)
            res+=1

print(res)