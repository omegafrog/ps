import math
N = 1000000

nums = {}


for i in range(3, N, 2):
    nums[i] = True

for i in range(3, math.floor(math.sqrt(N)), 2):
    cur = i*i
    if nums[cur] == False:
        continue
    while cur <= N:
        nums[cur] = False
        cur = cur+i

primes = []

for i in range(N):
    if i in nums and nums[i] == True:
        primes.append(i)


while True:
    num = int(input())
    if num == 0:
        exit()
    startIdx = 0
    endIdx = len(primes)-1
    for a in primes:
        if a > num/2:
            print("Goldbach's conjecture is wrong.")
            break
        if nums[num - a] == True:
            print(str(num)+" = "+str(a)+" + " + str(num-a))
            break
