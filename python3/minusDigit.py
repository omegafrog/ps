# 2089
import math


def getMinusDigit(a):
    res = []
    while a != 1 and a != 0:
        b = a/(-2)
        if b < 0:
            b = math.ceil(b)
        else:
            b = math.ceil(b)
        res.append(a-(-2)*b)
        a = b
    res.append(a)
    res.reverse()
    return res


n = int(input())
res = getMinusDigit(n)
while res and res[0] == 0:
    res = res[1:]

if len(res) == 0:
    print(0)
    exit()

for num in res:
    print(num, end="")
