import sys

N, x = map(int, sys.stdin.readline().rstrip().split())
inputs = list(map(int, sys.stdin.readline().rstrip().split()))


def bsearchMin(inputs, start, end, target):
    if end < start:
        return None
    mid = (end - start) // 2 + start
    # print(mid)
    if mid == 0 or inputs[mid] == target and inputs[mid - 1] < target:
        return mid
    elif inputs[mid] >= target:
        return bsearchMin(inputs, start, mid, target)
    else:
        return bsearchMin(inputs, mid + 1, end, target)


def bsearchMax(inputs, start, end, target):
    if end < start:
        return None
    mid = (end - start) // 2 + start
    # print(mid)
    if mid == len(inputs) - 1 or inputs[mid] == target and inputs[mid + 1] > target:
        return mid
    elif inputs[mid] > target:
        return bsearchMax(inputs, start, mid, target)
    else:
        return bsearchMax(inputs, mid + 1, end, target)


maxVal = bsearchMax(inputs, 0, len(inputs), x)
minVal = bsearchMin(inputs, 0, len(inputs), x)
if maxVal is not None and minVal is not None:
    print(maxVal - minVal + 1)
