import sys


class Node:
    def __init__(self, data, prev):
        self.data = data
        self.next = None
        self.prev = prev


class Editor:
    def __init__(self, string):
        self.head = None
        self.tail = None
        self.cursor = None
        self.size = 0
        for i in range(len(string)):
            if self.head == None:
                self.head = Node(string[i], None)
                self.head.prev = self.head
                self.cursor = self.head
            else:
                self.cursor.next = Node(string[i], self.cursor)
                self.cursor = self.cursor.next
            self.size += 1

        self.cursor.next = Node("", self.cursor)
        self.cursor = self.cursor.next
        self.tail = self.cursor

    def L(self):
        self.cursor = self.cursor.prev

    def D(self):
        if self.cursor == self.tail:
            return
        self.cursor = self.cursor.next

    def B(self):
        if self.cursor == self.head:
            return
        target = self.cursor.prev
        if target == self.head:
            self.head = self.cursor
            self.head.prev = self.head
        else:
            before = self.cursor.prev.prev
            self.cursor.prev = before
            before.next = self.cursor
        self.size -= 1

    def P(self, data):
        if self.cursor == self.head:
            newNode = Node(data, None)
            newNode.next = self.head
            newNode.prev = newNode
            self.head.prev = newNode
            self.head = newNode

        elif self.cursor == self.tail:
            newNode = Node(data, None)
            newNode.next = self.tail
            newNode.prev = self.tail.prev
            self.tail.prev.next = newNode
            self.tail.prev = newNode

        else:
            newNode = Node(data, None)
            newNode.next = self.cursor
            newNode.prev = self.cursor.prev
            self.cursor.prev.next = newNode
            self.cursor.prev = newNode

        self.size += 1

    def print(self):
        cur = self.head
        for i in range(self.size):
            print(cur.data, end="")
            cur = cur.next


inputString = sys.stdin.readline().rstrip()
editor = Editor(inputString)
cnt = int(input())
for i in range(cnt):
    cmdLine = sys.stdin.readline().rstrip().split(" ")
    cmd = cmdLine[0]
    arg = 0
    if len(cmdLine) > 1:
        arg = cmdLine[1]

    if cmd == "P":
        editor.P(arg)
    elif cmd == "L":
        editor.L()
    elif cmd == "B":
        editor.B()
    elif cmd == "D":
        editor.D()
    else:
        break

editor.print()
