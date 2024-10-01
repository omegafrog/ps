import sys

[N,M] = list(map(int,sys.stdin.readline().rstrip().split()))

coins=[]

for i in range(N):
    coins.append(int(input()))

minCoins = [-1]*(M+1)

# minCoins[i] = i원을 만들기 위한 최소 화폐 개수
# minCoins[i] = min(minCoins[i-coins[j]])+1

minCoins[0] = 0

for i in range(1,M+1):
    for coin in coins:
        cand = 987654321
        if i - coin >=0:
            cand = min(cand,minCoins[i-coin])
        
        if cand == 987654321 or cand == -1:
            continue
        minCoins[i] = cand+1
    
print(minCoins[i])