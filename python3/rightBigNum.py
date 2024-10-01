import sys

n = int(input())
nums = list(map(int, sys.stdin.readline().rstrip().split(" ")))


stack = []
res = []

for i in range(len(nums)-1, -1, -1):
    while stack and stack[-1] <= nums[i]:
        stack.pop()
    if len(stack) == 0:
        res.append(-1)
    else:
        res.append(stack[-1])
    stack.append(nums[i])

for i in reversed(res):
    print(i, end=" ")
