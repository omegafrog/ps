# 여러개의 숫자 카드 중에서 가장 높은 숫자가 쓰인 카드 한 장을 뽑는 게임이다.
# 1. 숫자가 쓰인 카드들이 N x M 형태로 놓여 있다. N은 행, M은 열이다
# 2. 먼저 뽑고자 하는 카드가 포함된 행을 선택
# 그다음 선택한 행에 포함된 카드들 중 가장 숫자가 낮은 카드를 뽑아야 한다.
# 첫째 줄에 N, M이 주어진다. ( 1 <= N, M <= 100)
# 둘째 줄에 N개의 줄에 걸쳐 숫자가 주어진다.
import sys;

cards = []
biggest = -1

[N, M] = list(map(int, sys.stdin.readline().rstrip().split(" ")))
for i in range(N):
    tmp = list(map(int, sys.stdin.readline().rstrip().split(" ")))
    tmp.sort()
    biggest = max(biggest, tmp[0])
    
print(biggest)

