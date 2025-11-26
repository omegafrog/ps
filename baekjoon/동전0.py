import sys

N, K = list(map(int, sys.stdin.readline().rstrip().split()))

coins = []
for _ in range(N):
    coins.append(int(input()))

coins.reverse()

idx = 0
cnt = 0
while K>0 :
    # print("K:",K)
    while K < coins[idx]:
        idx+=1
    # print("curCoin:",coins[idx])
    K = K-coins[idx]
    cnt+=1

print(cnt)