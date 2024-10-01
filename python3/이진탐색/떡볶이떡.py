import sys

[N,M] = list(map(int, sys.stdin.readline().rstrip().split()))
dducks=list(map(int, sys.stdin.readline().rstrip().split()))

totalDduckSum = 0
for dduck in dducks:
    totalDduckSum+=dduck

def bsearch(arr, start, end, dduckSum):
    mid = (end-start)//2 + start
    print("mid:%d" % mid)
    cuttedDduckSum = 0
    for dduck in arr:
        cuttedDduck = dduck-mid
        if cuttedDduck >0:
            cuttedDduckSum+=cuttedDduck
    
    if cuttedDduckSum < dduckSum:
        return bsearch(arr, start, mid, dduckSum)
    elif cuttedDduckSum == dduckSum:
        return mid
    else: return bsearch(arr, mid+1, end, dduckSum)

print(bsearch(dducks, 0, 2000000000, M))
    