# [(N1,M1), (N2,M2)...(Nn,Mn)]으로 저장해둠. 그리고 백트래킹으로 인접한 2개를 선택. 곱하고 결과를 더하고 재귀호출. 비어있으면 종료.
# 2개를 선택해서 (Np, Mp), (Nq,Mq) -> (Np, Mq)로 만들고, 곱한 횟수 저장해둠. 
# 이후 횟수 + 재귀호출. 
# 재귀호출이후 다시 복구해야됨. -> 여기서 리스트면 O(N)번이 드는데...
# 행렬 길이가 500이니까, depth는? 1번 호출할때마다 1개씩 줄으니까, N-1번해야돼네
# 그럼 결국 N^N?
# 메모이제이션을 도입하면 될거같은데 아니면 그리디
# 메모이제이션이구나. 유명한 문제인듯
# i부터 j까지 곱의 결과를 메모이제이션으로 저장
# 행렬곱은 ABCD -> AB + CD + AB의 행 x AB의 열 x CD의 열 으로 구할수 있음 -> 이걸 알았으면 더 쉽게 접근할 수 있었는데 

import sys

N = int(input())

inputs = []

for _ in range(N):
    inputs.append(list(map(int, sys.stdin.readline().rstrip().split())))

mem =[ [-1]*(N+1) for _ in range(N+1)]


if len(inputs) == 2:
    print(inputs[0][0]*inputs[0][1]*inputs[1][1])
    exit(0)


start = 0
end = len(inputs)
mid = len(inputs)//2


# [start, end]
def recursive(start, end, mem, inputs):
    if end-start == 1:
        return (inputs[start][0]*inputs[start][1]*inputs[end][1])
    if end-start == 0:
        return 0


    res = mem[start][end]
    if res !=-1:
        return res
    
    cand = 987654321
    for k in range(end-start):
        cand = min(cand, recursive(start, start + k, mem, inputs)+recursive(start + k+1,end,mem, inputs)+ inputs[start][0]*inputs[start+k][1]*inputs[end][1]) 
    mem[start][end] = cand
    return cand

print(recursive(0, len(inputs)-1, mem, inputs))


    


