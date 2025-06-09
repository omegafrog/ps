import sys

N, S = list(map(int, sys.stdin.readline().rstrip().split()))
nums = list(map(int, sys.stdin.readline().rstrip().split()))


left = -1
right = -1

sum = 0

minLen = 987654321


while right < len(nums):
    if sum >= S:
        minLen = min(minLen, right - left)
        left += 1
        if left >= len(nums):
            break
        sum -= nums[left]

    else:
        right += 1
        if right >= len(nums):
            break
        sum += nums[right]

    # print(sum, minLen, left, right)

if minLen == 987654321:
    print(0)
else:
    print(minLen)
