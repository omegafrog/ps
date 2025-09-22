import math

N = int(input())

if N == 2:
    print(1)
    exit(0)

primes = [1] * (N + 1)
primes[0] = 0
primes[1] = 0

for i in range(2, int(math.sqrt(N)) + 1):
    if primes[i] == 0:
        continue
    for j in range(i * i, N + 1, i):
        primes[j] = 0
primeList = [i for i, v in enumerate(primes) if v]

# print(primeList)
sum = 0

start = 0
end = 0


res = 0
sum = 0
while start < len(primeList):
    if sum < N:
        if end < len(primeList):
            sum += primeList[end]
            end += 1
    elif sum == N:
        # print(start, end)
        res += 1
        sum -= primeList[start]
        start += 1
    else:
        sum -= primeList[start]
        start += 1
print(res)
