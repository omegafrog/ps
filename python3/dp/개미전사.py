import sys

foods = []
# maxFoods[i] : 창고의 길이가 i일때 얻는 식량의 최대값
# maxFoods[i] = max(maxFoods[i-1],maxFoods[i-2]+foods[i])

N = int(input())
foods = list(map(int, sys.stdin.readline().rstrip().split()))

maxFoods = [0]*N

maxFoods[0] = foods[0]
maxFoods[1] = foods[1]

for i in range(2,N):
    maxFoods[i] = max(maxFoods[i-2]+foods[i], maxFoods[i-1])

print(maxFoods[N-1])