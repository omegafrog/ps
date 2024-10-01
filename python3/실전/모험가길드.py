import sys

N = int(input())

inputs = list(map(int, sys.stdin.readline().rstrip().split()))

sortedInputs = sorted(inputs)

groupCnt = 0

idx = 0
while len(sortedInputs) > idx:
    print("idx:",idx)
    curFear = sortedInputs[idx]
    biggest = sortedInputs[idx]
    tmp = [sortedInputs[idx]]
    while len(tmp) < biggest:
        idx+=1
        if idx >= len(sortedInputs):
            break
        biggest = max(biggest, sortedInputs[idx])
        tmp.append(sortedInputs[idx])
    if len(tmp) == biggest:
        groupCnt+=1
    idx+=1
print(groupCnt)

    
    

    

print(groupCnt)
        