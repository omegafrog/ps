n = int(input())

mem = []
for i in range(n+1):
    mem.append([])
    for j in range(10):
        mem[i].append(1)
mem[1][0] = 0


for i in range(2, n+1):
    for j in range(10):
        if j == 0:
            mem[i][0] = mem[i-1][1]
        elif j == 9:
            mem[i][9] = mem[i-1][8]
        else:
            mem[i][j] = mem[i-1][j-1]+mem[i-1][j+1]

res = 0
for j in range(10):
    res = (res % 1000000000+mem[n][j] % 1000000000) % 1000000000

print(res)
