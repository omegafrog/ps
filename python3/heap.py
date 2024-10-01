from collections import *
import math
from queue import PriorityQueue
from heapq import heappush, heappop


class Heap:
    def __init__(self):
        self.data = [-1]

    def enqueue(self, data):
        curIdx = len(self.data)
        self.data.append(data)
        parentIdx = math.floor(curIdx/2)
        while parentIdx > 0 and self.data[parentIdx] > self.data[curIdx]:
            tmp = self.data[parentIdx]
            self.data[parentIdx] = self.data[curIdx]
            self.data[curIdx] = tmp
            curIdx = parentIdx
            parentIdx = math.floor(curIdx/2)

    def dequeue(self):
        result = self.data[1]
        self.data[1] = self.data[-1]
        self.data.pop()
        curIdx = 1
        while curIdx*2 <= len(self.data):
            childIdxs = [curIdx*2, curIdx*2+1]
            for childIdx in childIdxs:
                if self.data[curIdx] > self.data[childIdx]:
                    tmp = self.data[curIdx]
                    self.data[curIdx] = self.data[childIdx]
                    self.data[childIdx] = tmp
                    curIdx = childIdx
                    break

        return result

    def display(self):
        height = math.floor(math.log2(len(self.data)))
        # print(self.data)
        for i in range(1, len(self.data)):
            tabs = int(math.pow(2, height-math.floor(math.log2(i))))
            if math.log2(i) == int(math.log2(i)):
                print("\n")
            for j in range(tabs):
                print("\t", end='')
            print(self.data[i], end='')
            for j in range(tabs):
                print("\t", end='')
        print()


n = 4
edges = [[[1, 2], [3, 1]], [[2, 4]], [[0, 2]], [1]]


def dijkstra(start, n, edges):
    visited = [False] * n
    costs = [987654321] * n
    costs[start] = 0
    heap = PriorityQueue()

    heap.put((0, start))
    visited[start] = True

    while not heap.empty():
        cur = heap.get()
        visited[cur[1]] = True
        for edge in edges[cur[1]]:
            if visited[edge[0]] == False:
                if costs[edge[0]] > costs[cur] + edge[1]:
                    costs[edge[0]] = costs[cur]+edge[1]
                    heap.put((edge[1], edge[0]))


h = Heap()
h.enqueue(3)
h.enqueue(1)
h.enqueue(4)
h.enqueue(8)
h.enqueue(-1)
h.enqueue(-5)
h.display()
print(h.dequeue())
h.display()
que = deque()

que = PriorityQueue()

heapq
