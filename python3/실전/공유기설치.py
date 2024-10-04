# 가장 인접한 두 공유기 사이의 거리를 최대로 한다
# 가장 인접한 두 공유기 사이의 거리가 n일때, 1번집부터 공유기를 깔아서 c개를 정확히 깔 수 있다면 정답이다.
# c보다 많이 깔 수 있다면, 거리를 늘리고, c보다 적게 깔 수 있다면 거리를 줄인다.

# 일단 정의가 이상함
# 가장 인접한 두 공유기 사이의 거리가 n일때, 만약 다음 집이 두 공유기 사이의 거리보다 멀다면?
# 다음 집에 공유기를 추가해야됨
# 20째 줄처럼 공유기 거리보다 먼 경우에도 달아야 함.
# 그리고 C가 같은 경우에도 거리를 늘려서 다시 해봐야함
#
# 어렵다.
import sys

N, C = list(map(int, sys.stdin.readline().rstrip().split()))

homes = []
for _ in range(N):
    homes.append(int(input()))

homes.sort()


def bisect(homes, start, end):
    gap = (end - start) // 2 + start
    if start == end - 1:
        return gap
    if end < start:
        return None
    cnt = 1
    cur = homes[0]
    for i in range(N):
        if cur + gap <= homes[i]:
            cur = homes[i]
            cnt += 1

    print("cnt:", cnt)
    print("gap:", gap)
    if cnt < C:
        return bisect(homes, start, gap)
    else:
        return bisect(homes, gap + 1, end)


print(bisect(homes, 1, homes[-1] - homes[0]))
