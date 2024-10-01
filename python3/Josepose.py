arr = []


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.before = None


head = None
cur = None
size = 0

[n, k] = map(int, input().split(" "))
for i in range(1, n+1):
    if i == 1:
        head = Node(i)
        cur = head
    else:
        newNode = Node(i)
        newNode.before = cur
        cur.next = newNode
        cur = cur.next
    size += 1

cur.next = head
head.before = cur


res = []
idx = 0
cur = head
while idx < k-1:
    cur = cur.next
    idx += 1


while size > 0:
    res.append(cur.data)
    beforeNode = cur.before
    nextNode = cur.next
    beforeNode.next = nextNode
    nextNode.before = beforeNode
    cur = nextNode
    for i in range(k-1):
        cur = cur.next
    size -= 1


print("<", end="")
for i in range(len(res)):
    if i != len(res)-1:
        print(str(res[i])+", ", end="")
    else:
        print(str(res[i])+">")
