import math
import sys
sys.setrecursionlimit(10 ** 6)

global groupCnt
global rootNode
groupCnt = 1

class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = None
        self.right = None

def solution(k, num, links):
    global groupCnt
    global rootNode
    answer = 0
    root = [True]*len(links)
    for i in range(len(links)):
        link = links[i]
        if link[0] != -1:
            root[link[0]] = False
        if link[1] != -1:
            root[link[1]] = False
    
    rootNode = -1
    for i in range(len(root)):
        if root[i] == True:
            rootNode = i
            break
            
    res = binarySearch(0, 10000, k, rootNode, links, num)
    
    
    
    return answer


def search(maxNum, root, links,num, values):
    global groupCnt
    global rootNode
    if root == -1:
        return 0
    
    leftVal = search(maxNum, links[root][0], links, num, values)
    rightVal = search(maxNum, links[root][1], links, num, values)
    
    totalSum = leftVal + rightVal + num[root]
    
    # 단말 노드일 경우 그냥 리턴
    if links[root][0] == None and links[root][1] == None:
        return num[root]

    # 분리 안함
    if totalSum <= maxNum:
        if rootNode == root:
            values.append(totalSum)
        return leftVal+ rightVal+ num[root]
    # 왼쪽 분리    
    elif totalSum > maxNum and totalSum - leftVal <= maxNum:
        groupCnt+=1
        if rootNode == root:
            values.append(rightVal+ num[root])
        values.append(leftVal)
        return rightVal + num[root]
    # 오른쪽 분리
    elif totalSum > maxNum and totalSum - rightVal <= maxNum:
        values.append(rightVal)
        groupCnt+=1
        if rootNode == root:
            values.append(leftVal+ num[root])
        return leftVal + num[root]

    # 모두 분리
    else:
        groupCnt+=2
        values.append(leftVal)
        values.append(rightVal)
        return num[root]


def binarySearch(start, end, k, root, links, num):
    global groupCnt
    mid = start+math.floor((end-start)/2)
    values = []
    groupCnt = 1
    search(mid, root, links, num, values)
    if groupCnt > k:
        return binarySearch(mid+1, end, k, root, links, num)
    elif groupCnt < k:
        return binarySearch(start, mid-1, k, root, links, num)
    else:
        biggest = -1
        for value in values:
            biggest = max(biggest, value)
        return biggest


k =3
num = [12, 30, 1, 8, 8, 6, 20, 7, 5, 10, 4, 1]
links = [[-1, -1], [-1, -1], [-1, -1], [-1, -1], [8, 5], [2, 10], [3, 0], [6, 1], [11, -1], [7, 4], [-1, -1], [-1, -1]]
solution(k, num, links)