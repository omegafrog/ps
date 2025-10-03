import sys
T = int(input())

for _ in range(T):
    K = int(input())
    files = list(map(int, sys.stdin.readline().rstrip().split()))

    n = len(files)

    mem = [[-987654321]*(n+1) for _ in range(n+1)]
    sums = []
    sum = 0
    for file in files:
        sum+=file 
        sums.append(sum)

    for i in range(n):
        mem[i][i] = 0
    
    for i in range(n-1):
        mem[i][i+1] = files[i]+files[i+1]

    for i in range(2, len(files)):
        for start in range(n-i):
            cand = 987654321
            end = start+i
            for k in range(i):
                totalsum = 0
                if start == 0:
                    totalsum = sums[end]
                else:
                    totalsum = sums[end]-sums[start-1]
                cand = min(cand, mem[start][start+k]+mem[start+k+1][end] + totalsum)
                # print("start:", start, "end:", end, "k:",k, "cand:", cand)
            mem[start][end]=cand
    print(mem[0][n-1])

                
        
