N, K = list(map(int, input().rstrip().split()))
coins = []

for _ in range(N):
    coins.append(int(input()))

mem = [0] * (K + 1)

mem[0] = 1

for coin in coins:
    for i in range(coin, K + 1):
        mem[i] += mem[i - coin]

print(mem)
print(mem[K])
