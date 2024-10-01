import sys
N = int(input())
Narr = list(map(int, sys.stdin.readline().rstrip().split()))
M = int(input())
Marr = list(map(int, sys.stdin.readline().rstrip().split()))
Narr = sorted(Narr)

def bsearch(arr,target,start, end):
    mid = (end-start)//2 + start
    
    if target == arr[mid]:
        return True
    if end == start:
        return False
    
    if arr[mid] < target:
        return bsearch(arr, target, mid+1, end)
    else:
        return bsearch(arr, target, start, mid)

for m in Marr:
    if bsearch(Narr, m, 0, len(Narr)-1) == True:
        print("yes")
    else: print("no")