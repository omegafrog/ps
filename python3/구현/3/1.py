import sys

directions = [[-1,0],[0,1],[1,0],[0,-1]]

[N,M] = list(map(int, sys.stdin.readline().rstrip().split()))


field = []
# y, x, direction
cur = list(map(int, sys.stdin.readline().rstrip().split()))

cur = [cur[0]-1, cur[1]-1, cur[2]]

for i in range(N):
    inputs = list(map(int, sys.stdin.readline().rstrip().split()))
    field.append(inputs)

allImpossible = 0
res = 0

while True:
    nextDir = (cur[2]-1+4)%4
    nextPos = [cur[0]+directions[nextDir][0], cur[1]+directions[nextDir][1]]

    if allImpossible==4:
        backPos = [cur[0]-directions[cur[2]][0], cur[1]-directions[cur[2]][1]]
        if backPos[0] <0 or backPos[0] > N or backPos[1] <0 or backPos[1] > M:
            break
        cur = [backPos[0], backPos[1], cur[2]]
        allImpossible = 0

    if nextPos[0]<0 or nextPos[0]>N or nextPos[1] < 0 or nextPos[1]>M:
        allImpossible+=1
        cur = [cur[0], cur[1], nextDir]
        continue

    if field[nextPos[0]][nextPos[1]] == 0:
        cur = [nextPos[0],nextPos[1], nextDir]
        field[nextPos[0]][nextPos[1]] = 2
        res+=1
    else:
        cur = [cur[0], cur[1], nextDir]
        allImpossible+=1

print(res)

