N = int(input())


inputs = list(map(int, input().split(" ")))

tmp = list(map(int, input().split(" ")))
T = tmp[0]
P = tmp[1]

shirts = 0

for num in inputs:
    if num % T == 0:
        shirts += num // T
    else:
        shirts += num // T + 1

print(shirts)

print(N // P, N % P)
