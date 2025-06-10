from collections import deque

A, B = list(map(int, input().rstrip().split()))

que = deque()
mem = {}
mem[A] = 0
que.append(A)

while len(que) > 0:
    i = que.popleft()
    if i not in mem.keys():
        continue
    if i * 2 <= B:
        mem[i * 2] = mem[i] + 1
        que.append(i * 2)
    tmp = int(str(i) + "1")
    if tmp <= B:
        mem[tmp] = mem[i] + 1
        que.append(tmp)

# print(mem)

if B not in mem.keys():
    print(-1)
else:
    print(mem[B] + 1)
