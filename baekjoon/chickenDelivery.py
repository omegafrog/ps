import sys

N, M = list(map(int, input().rstrip().split()))

data = []

chickens = []
house = []

for y in range(N):
    line = list(map(int, sys.stdin.readline().rstrip().split()))
    for x in range(N):
        if line[x] == 1:
            house.append([y, x])
        elif line[x] == 2:
            chickens.append([y, x])

global smallest
smallest = 987654321


def selectChicken(deps, chickenIdx, chickens, house, diff):
    # print(chickenIdx, deps)
    if deps == M:
        # print(diff)
        global smallest
        smallest = min(smallest, sum(diff))
        return
    for i in range(chickenIdx, len(chickens)):
        original = diff[:]
        for j in range(len(house)):
            diff[j] = min(
                diff[j],
                abs(chickens[i][0] - house[j][0]) + abs(chickens[i][1] - house[j][1]),
            )
        selectChicken(deps + 1, i + 1, chickens, house, diff)
        diff = original[:]


diff = [987654321] * (len(house))

# print(house, chickens)

selectChicken(0, 0, chickens, house, diff)

# print(diff)
print(smallest)
