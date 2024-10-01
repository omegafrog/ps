# 1373
import sys
import math

digit = sys.stdin.readline().rstrip()

digitList = []

for i in range(len(digit)-1, -1, -1):
    digitList.append(int(digit[i]))

while len(digitList) % 3 != 0:
    digitList.append(0)


res = []
for i in range(0, len(digitList), 3):
    res.append(str(4*digitList[i+2]+2*digitList[i+1]+1*digitList[i]))

res.reverse()
for num in res:
    print(num, end="")
