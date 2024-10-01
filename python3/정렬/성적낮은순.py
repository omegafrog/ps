import sys
N = int(input())

grades = []

for i in range(N):
    a = sys.stdin.readline().rstrip().split()
    grades.append([a[0], int(a[1])])

b = sorted(grades, key=lambda student: student[1])

for tmp in b:
    print(tmp[0], tmp[1])