import sys


class Queue:
    def __init__(self):
        self.capacity = 10001
        self.data = [0]*self.capacity
        self.front = -1
        self.rear = -1
        self.size = 0

    def push(self, x):
        self.rear = (self.rear+1) % self.capacity
        self.data.insert(self.rear, x)
        self.size += 1

    def pop(self):
        if self.empty() == 1:
            return -1
        self.front = (self.front+1) % self.capacity
        self.size -= 1
        return self.data[self.front]

    def Size(self):
        return self.size

    def empty(self):
        return 1 if self.front == self.rear else 0

    def Front(self):
        if self.empty() == 1:
            return -1
        return self.data[(self.front+1) % self.capacity]

    def Back(self):
        if self.empty() == 1:
            return -1
        return self.data[self.rear]


cnt = int(input())
q = Queue()
for i in range(cnt):
    cmdLine = sys.stdin.readline().rstrip().split(" ")
    cmd = cmdLine[0]
    arg = 0
    if len(cmdLine) > 1:
        arg = cmdLine[1]

    if cmd == "push":
        q.push(arg)
    elif cmd == "front":
        print(q.Front())
    elif cmd == "back":
        print(q.Back())
    elif cmd == "pop":
        print(q.pop())
    elif cmd == "size":
        print(q.Size())
    elif cmd == "empty":
        print(q.empty())
