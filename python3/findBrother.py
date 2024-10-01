# 17087
import sys
import gc


def getGCD(a, b):
    c = a % b
    while c != 0:
        a = b
        b = c
        c = a % b

    return b


[n, s] = list(map(int, sys.stdin.readline().rstrip().split(" ")))

A = list(map(int, sys.stdin.readline().rstrip().split(" ")))

A.append(s)

A.sort()

a = []

for i in range(len(A)-1):
    a.append(A[i+1]-A[i])

del A
gc.collect()

if len(a) == 1:
    print(a[0])
    exit()

gcd = getGCD(a[1], a[0])
for i in range(2, len(a)):
    gcd = getGCD(gcd, a[i])

print(gcd)
