import sys


n = int(input())

nums = list(map(int, sys.stdin.readline().rstrip().split(" ")))


numsMap = {}
stack = []
res = []

for num in nums:
    if num not in numsMap:
        numsMap[num] = 1
    else:
        numsMap[num] += 1

for i in range(len(nums)-1, -1, -1):
    while stack and numsMap[stack[-1]] <= numsMap[nums[i]]:
        stack.pop()

    if len(stack) == 0:
        res.append(-1)
    else:
        res.append(stack[-1])
    stack.append(nums[i])

for num in reversed(res):
    print(num, end=" ")
