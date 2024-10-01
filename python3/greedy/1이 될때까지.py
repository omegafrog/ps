# 어떤 수 N이 1이 될때까지 1을 빼거나 K로 나눈다
# 이때 K로 나눠떨어질때만 두번째를 선택할 수 있다.
# 2<= ㅜ <=100000, 2 <= K <= 10000
# 첫째 줄에 N, K가 주어진다. N>=K
# N이 1이 될때까지 최소 횟수를 반환해라

import sys;

[N, K] = list(map(int, sys.stdin.readline().rstrip().split(" ")))

cnt = 0
while N >1:
    if N%K==0:
        N=N/K
    else:
        N-=1
    cnt+=1

print(cnt)