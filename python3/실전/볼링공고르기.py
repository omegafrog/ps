import sys

[N,M] = list(map(int, sys.stdin.readline().rstrip().split()))

nums = list(map(int, sys.stdin.readline().rstrip().split()))

cnt = 0

for i in range(N):
    for j in range(i+1, N):
       if nums[i] != nums[j]:
           cnt+=1 
print(cnt)