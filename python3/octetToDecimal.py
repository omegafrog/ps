# 1212
import sys
import math


def toDigit(a):
    res = []
    while a > 1:
        res.append(a % 2)
        a /= 2
        a = int(a)

    res.append(a)

    while len(res) < 3:
        res.append(0)

    res.reverse()
    return res


n = input()
res = []
for i in range(len(n)):
    digit = toDigit(int(n[i]))
    for j in digit:
        res.append(j)

while res and res[0] == 0:
    res = res[1:]

if len(res) == 0:
    res.append(0)


for num in res:
    print(num, end="")
