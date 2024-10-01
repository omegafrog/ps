import sys

numstr = sys.stdin.readline().rsplit()
nums = []

for num in numstr[0]:
    nums.append(int(num))

res = 0

for num in nums:
    if num == 0:
        continue
    elif res == 0:
        res+=num
    else:
        res*=num

print(nums)

print(res)
    