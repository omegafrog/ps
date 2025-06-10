import sys

N, K = list(map(int, sys.stdin.readline().rstrip().split()))

grade = list(map(int, sys.stdin.readline().rstrip().split()))


grade = list(map(lambda x: x * 100 // N, grade))

gradeList = []
for num in grade:
    if 0 <= num and num <= 4:
        gradeList.append(1)
    elif 4 < num and num <= 11:
        gradeList.append(2)
    elif 11 < num and num <= 23:
        gradeList.append(3)
    elif 23 < num and num <= 40:
        gradeList.append(4)
    elif 40 < num and num <= 60:
        gradeList.append(5)
    elif 60 < num and num <= 77:
        gradeList.append(6)
    elif 77 < num and num <= 89:
        gradeList.append(7)
    elif 89 < num and num <= 96:
        gradeList.append(8)
    else:
        gradeList.append(9)

for num in gradeList:
    print(num, end=" ")
