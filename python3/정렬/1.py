N = int(input())

a = []
for i in range(N):
    a.append(input())

b=sorted(a)
b.reverse()
print(b)