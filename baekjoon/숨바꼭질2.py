from collections import deque

N, K = list(map(int, input().rstrip().split()))

ways = [[987654321, 0] for _ in range(200001)]
ways[N][0] = 0
ways[N][1] = 1

q = deque([])
q.append(N)

while len(q) > 0:
    # print(q)
    cur = q.popleft()
    if cur - 1 >= 0:
        if ways[cur - 1][0] > ways[cur][0] + 1:
            ways[cur - 1][0] = ways[cur][0] + 1
            ways[cur - 1][1] += ways[cur][1]
            q.append(cur - 1)
        elif ways[cur - 1][0] == ways[cur][0] + 1:
            ways[cur - 1][0] = ways[cur][0] + 1
            ways[cur - 1][1] += ways[cur][1]

    if cur + 1 <= 200000:
        if ways[cur + 1][0] > ways[cur][0] + 1:
            ways[cur + 1][0] = ways[cur][0] + 1
            ways[cur + 1][1] += ways[cur][1]
            q.append(cur + 1)
        elif ways[cur + 1][0] == ways[cur][0] + 1:
            ways[cur + 1][0] = ways[cur][0] + 1
            ways[cur + 1][1] += ways[cur][1]
    if cur * 2 <= 200000:
        if ways[cur * 2][0] > ways[cur][0] + 1:
            ways[cur * 2][0] = ways[cur][0] + 1
            ways[cur * 2][1] += ways[cur][1]
            q.append(cur * 2)
        elif ways[cur * 2][0] == ways[cur][0] + 1:
            ways[cur * 2][0] = ways[cur][0] + 1
            ways[cur * 2][1] += ways[cur][1]

# print(ways)
print(ways[K][0])
print(ways[K][1])
