import sys
from collections import deque

sys.setrecursionlimit(100000)


class node:
    def __init__(self, parent, num):
        self.parent = parent
        self.children = []
        self.num = num

    def appendChild(self, num):
        child = node(self, num)
        self.children.append(child)
        return child


N, R, Q = list(map(int, input().rstrip().split()))

subTrees = [-1] * (N + 1)
edges = [list() for _ in range(N + 1)]

head = node(None, R)
for _ in range(N - 1):
    u, v = list(map(int, sys.stdin.readline().rstrip().split()))
    edges[u].append(v)
    edges[v].append(u)

# print(edges)

q = deque()
q.append(head)
while len(q) > 0:
    cur = q.popleft()
    num = cur.num
    for next in edges[num]:
        if cur.parent is None or cur.parent.num != next:
            child = cur.appendChild(next)
            q.append(child)


# print(head.num)
# print([x.num for x in head.children])


def getSubTreeCnt(head, subTrees):
    if len(head.children) == 0:
        subTrees[head.num] = 1
        return 1

    res = subTrees[head.num]
    if res != -1:
        return res
    res = 0
    for child in head.children:
        res += getSubTreeCnt(child, subTrees)
    res += 1
    subTrees[head.num] = res
    return res


getSubTreeCnt(head, subTrees)

# print(subTrees)

for _ in range(Q):
    U = int(sys.stdin.readline().rstrip().split()[0])
    print(subTrees[U])
