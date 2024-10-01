import sys


class Dequeue:
    def __init__(self):
        self.capacity = 10000
        self.data = [0]*self.capacity
        self.size = 0
        self.front = 0
        self.rear = 0

    def push_front(self, x):
        self.data[self.front] = x
        self.front = (self.front-1+self.capacity) % self.capacity
        self.size += 1

    def push_back(self, x):
        self.rear = (self.rear+1) % self.capacity
        self.data[self.rear] = x
        self.size += 1

    def pop_front(self):
        if self.size == 0:
            return -1
        self.front = (self.front + 1) % self.capacity
        self.size -= 1
        return self.data[self.front]

    def pop_back(self):
        if self.size == 0:
            return -1
        res = self.data[self.rear]
        self.rear = (self.rear-1+self.capacity) % self.capacity
        self.size -= 1
        return res

    def Size(self):
        return self.size

    def Emtpy(self):
        if self.size == 0:
            return 1
        else:
            return 0

    def Front(self):
        if self.size == 0:
            return -1
        return self.data[(self.front+1) % self.capacity]

    def Rear(self):
        if self.size == 0:
            return -1
        return self.data[self.rear]


N = int(input())
deck = Dequeue()
for i in range(N):
    cmdLine = sys.stdin.readline().rstrip().split(" ")
    cmd = cmdLine[0]
    arg = 0
    if len(cmdLine) > 1:
        arg = cmdLine[1]

    if cmd == "push_back":
        deck.push_back(arg)
    elif cmd == "push_front":
        deck.push_front(arg)
    elif cmd == "front":
        print(deck.Front())
    elif cmd == "back":
        print(deck.Rear())
    elif cmd == "size":
        print(deck.Size())
    elif cmd == "empty":
        print(deck.Emtpy())
    elif cmd == "pop_front":
        print(deck.pop_front())
    elif cmd == "pop_back":
        print(deck.pop_back())
