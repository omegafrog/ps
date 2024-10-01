import sys

[N, K] = list(map(int, sys.stdin.readline().rstrip().split()))

A = list(map(int, sys.stdin.readline().rstrip().split()))
B = list(map(int, sys.stdin.readline().rstrip().split()))

A = sorted(A)
B = sorted(B, reverse=True)

idx = 0
for k in range(K):
    if A[idx] <B[idx]:
        tmp = A[idx]
        A[idx]=B[idx]
        B[idx]=A[idx]
        idx+=1
    

res = 0
for num in A:
    res+=num

print(res)