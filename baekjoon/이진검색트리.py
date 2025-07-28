# 맨 첫번째 값이 root 값이고, 이 값보다 작은 것 / 큰 것으로 나누기
# 배열의 크기가 1일때까지 나누기
# head node를 리턴하도록 하기
#
# 노드가 최대 10000개니까 log 10000 ~= 20 depth 정도

import sys

sys.setrecursionlimit(10001)

vals = []
while True:
    try:
        tmp = int(sys.stdin.readline().rstrip())
        vals.append(tmp)
    except:
        break


# [start, end)
def createTree(vals, start, end):
    if end - start == 0:
        return
    root = vals[start]
    if end - start == 1:
        print(root)
        return
    idx = start + 1
    while idx < end:
        if vals[idx] > root:
            break
        idx += 1

    createTree(vals, start + 1, idx)
    createTree(vals, idx, end)
    print(root)
    return


createTree(vals, 0, len(vals))


# def rlv(root):
#     if root is None:
#         return
#     print(root[2])
#     rlv(root[0])
#     rlv(root[1])
#
#
# # rlv(root)
#
#
# def lvr(root):
#     if root is None:
#         return
#     lvr(root[0])
#     lvr(root[1])
#     print(root[2])
#
#
# lvr(root)
