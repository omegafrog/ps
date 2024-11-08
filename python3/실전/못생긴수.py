n = int(input())

res = [1]

for i in range(n):
    cur = res[i]

    res.append(cur * 2)
    res.append(cur * 3)
    res.append(cur * 5)

    res = list(set(res))
    res.sort()

print(res[n - 1])
