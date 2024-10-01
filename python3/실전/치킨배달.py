import sys
from itertools import combinations

[N,M] = list(map(int, sys.stdin.readline().rstrip().split()))
grid = []

for i in range(N):
    grid.append(list(map(int, sys.stdin.readline().rstrip().split())))

chickens= []
homes = []
for y in range(N):
    for x in range(N):
        if grid[y][x] == 2:
            chickens.append([y,x])
        if grid[y][x] == 1:
            homes.append([y,x])



chickenStreet = 987654321
for i in range(1,M+1):
    chickenCombs = list(combinations(chickens, i))
    for combs in chickenCombs:
        smallest = [987654321]*len(homes)
        for chicken in combs:
            idx = 0
            for home in homes:
                smallest[idx] = min(smallest[idx], abs(chicken[0]-home[0])+abs(chicken[1]-home[1]))
                idx+=1
        tmp = 0
        for i in smallest:
            tmp+=i    
        chickenStreet = min(chickenStreet, tmp)

print(chickenStreet)
