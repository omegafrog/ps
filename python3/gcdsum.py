import sys


def getGCD(a, b):
    c = a % b
    while c != 0:
        a = b
        b = c
        c = a % b

    return b


t = int(input())

for i in range(t):
    s = list(map(int, sys.stdin.readline().strip().split(" ")))
    n = s[0]
    res = 0
    for j in range(1, n+1):
        for k in range(j+1, n+1):
            res += getGCD(s[j], s[k])
    print(res)
