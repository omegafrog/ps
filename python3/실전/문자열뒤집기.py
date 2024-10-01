import sys

numstr = sys.stdin.readline().rstrip().split()

numstr = numstr[0]
cnt0=0
cnt1=0
idx = 0
while idx < len(numstr):
    cur = numstr[idx]
    isZero = cur == '0'
    tmp = cur
    while cur == tmp:
        idx+=1
        if idx >= len(numstr): break
        cur = numstr[idx]
    
    if isZero: cnt0+=1
    else: cnt1+=1

print(cnt0,cnt1)

if cnt0>cnt1 and cnt1>0:
    print(cnt1)
else: print(cnt0)

