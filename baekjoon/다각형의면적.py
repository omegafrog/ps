# 문제
# 2차원 평면상에 N(3 ≤ N ≤ 10,000)개의 점으로 이루어진 다각형이 있다. 이 다각형의 면적을 구하는 프로그램을 작성하시오.
#
# 입력
# 첫째 줄에 N이 주어진다. 다음 N개의 줄에는 다각형을 이루는 순서대로 N개의 점의 x, y좌표가 주어진다. 좌표값은 절댓값이 100,000을 넘지 않는 정수이다.
#
# 출력
# 첫째 줄에 면적을 출력한다. 면적을 출력할 때에는 소수점 아래 둘째 자리에서 반올림하여 첫째 자리까지 출력한다.
#
# 예제 입력 1
# 4
# 0 0
# 0 10
# 10 10
# 10 0
#
# 예제 출력 1
# 100.0
#

# 전체 사각형 - 연석된 두 점을 이은 선을 한 변으로 하는 사다리꼴 넓이의 합

import sys

n = int(input())

points = []


for _ in range(n):
    point = list(map(int, sys.stdin.readline().rstrip().split()))
    points.append(point)

res1 = 0
res2 = 0
points.append(points[0])
for i in range(len(points) - 1):
    x = points[i][0]
    y = points[i + 1][1]
    res1 += x * y

    x2 = points[len(points) - i - 1][0]
    y2 = points[len(points) - i - 1 - 1][1]
    res2 += x2 * y2


print(round(abs(res1 - res2) / 2, 1))
