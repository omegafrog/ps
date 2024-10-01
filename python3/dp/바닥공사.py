import sys

# maxTiles[i] = 가로의 길이가 i일때 덮개 경우의 수
# 마지막 타일을 2x2를 쓰는 경우 + 1x2를 쓰는 경우 -> maxTiles[i-2]+2
# 마지막 타일을 2x1을 쓰는 경우 -> maxTiles[i-1]+1
# maxTiles[i] = maxTiles[i-2]+2 + maxTiles[i-1]+1

N = int(input())

maxTiles = [0]*(N+1)
maxTiles[1] = 1
maxTiles[2] = maxTiles[1] + 2

for i in range(3, N+1):
    maxTiles[i] = maxTiles[i-2]*2 + maxTiles[i-1]

print(maxTiles)