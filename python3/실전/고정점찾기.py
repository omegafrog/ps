import sys

N = int(input())

arrs = list(map(int, sys.stdin.readline().rstrip().split()))


def bisect(arrs, start, end):
    if end <= start:
        return -1
    mid = (end - start) // 2 + start
    if arrs[mid] == mid:
        return mid
    elif arrs[mid] > mid:
        return bisect(arrs, start, mid)
    else:
        return bisect(arrs, mid + 1, end)


print(bisect(arrs, 0, len(arrs)))
