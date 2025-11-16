import sys
# N = int(input())

# stairs = [0]
# for _ in range(N):
#     stairs.append(int(sys.stdin.readline()))
# # print(stairs)
# def recursive(cur, before, stairs):
#     # print(cur)
#     res = 0
#     if cur == N:
#         return stairs[N]
#     if cur > N:
#         return -1* 10000*300
#     if cur-before == 1:
#         res = recursive(cur+2, cur, stairs)+stairs[cur]
#     elif cur-before == 2:
#         res = max(recursive(cur+1, cur, stairs), recursive(cur+2, cur, stairs))+stairs[cur]
#     # print(cur, res)

#     return res

# result = max(recursive(2, 1, stairs), recursive(3, 1, stairs))+stairs[1]
# print(result)
N = int(input())

stairs = [0]
for _ in range(N):
    stairs.append(int(sys.stdin.readline()))

# 전꺼 밟고 올때 최대값/ 전꺼 안밟고 올때 최대값
mem = [[0,0] for _ in range(N+1)]


mem[1] = [stairs[1], stairs[1]]
if N >= 2:
    mem[2] = [stairs[1]+stairs[2], stairs[2]]

for i in range(3, N+1):
    mem[i][0] = mem[i-1][1]+stairs[i]
    mem[i][1] = max(mem[i-2][0], mem[i-2][1])+stairs[i]

# print(mem)

print(max(mem[N][0], mem[N][1]))
