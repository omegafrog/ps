# 플로이드 와샬을 돌려서 자신을 제외한 모든 노드를 방문 가능하게 되면 답이 됨
# 모든 간선의 가중치를 1로 두고 플로이드 와샬 실행
# 한 노드에서 출발하는 노드의 개수와 도착하는 노드의 개수를 세서 이게 모든 노드 수 -1이 되면 됨.
# 플로이드 와샬의 결과에서 초기값과 다른 값이라면 출발지에서 도착지로 연결되어 있다는 의미임.


import sys

INF = 987654321

N, M = list(map(int, sys.stdin.readline().rstrip().split()))


grades = []
for _ in range(N + 1):
    grades.append([INF] * (N + 1))


for _ in range(M):
    u, v = list(map(int, sys.stdin.readline().rstrip().split()))
    grades[u][v] = 1

for i in range(1, N + 1):
    for u in range(1, N + 1):
        for v in range(1, N + 1):
            grades[u][v] = min(grades[u][v], grades[u][i] + grades[i][v])


res = 0
for i in range(1, N + 1):
    cnt = 0
    for j in range(1, N + 1):
        if grades[i][j] != INF or grades[j][i] != INF:
            cnt += 1
    print(i, cnt)
    if cnt == N - 1:
        res += 1
print(res)
