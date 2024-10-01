import sys

dir = [[-1,0],[1,0],[0,-1],[0,1]]

n = int(input())
print(n)
ops = sys.stdin.readline().rstrip().split(" ")

cur = [1,1]

for op in ops:
    nextDir = cur
    if op == 'L':
        nextDir = [cur[0]+dir[0][0], cur[1]+dir[0][1]]
    if op == 'R':
        nextDir = [cur[0]+dir[1][0], cur[1]+dir[1][1]]
    if op == 'U':
        nextDir = [cur[0]+dir[2][0], cur[1]+dir[2][1]]
    if op == 'D':
        nextDir = [cur[0]+dir[3][0], cur[1]+dir[3][1]]
    if 0< nextDir[0] and nextDir[0] < n and 0 < nextDir[1] and nextDir[1] < n:
        cur = nextDir
        print(op, cur, nextDir)
    else:
        continue

print(cur[1],cur[0])
