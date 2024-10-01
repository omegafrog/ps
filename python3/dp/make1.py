import sys
mem = []

X = int(input())

for i in range(X+1):
    mem.append(0)

mem[0] = 0
mem[1] = 0

for i in range(2,X+1):
    div2 = 987654321
    div3 = 987654321
    div5 = 987654321
    if i%2==0:
        div2=mem[i//2]
    if i%3==0:
        div3=mem[i//3]
    if i%5==0:
        div5=mem[i//5]
    mem[i] = min(div2,div3,div5,mem[i-1])+1

print(mem[X])
