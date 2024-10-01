import sys

N = int(input())

nums = list(map(int, sys.stdin.readline().rstrip().split()))

nums = sorted(nums)

sums = nums

target = 1

for x in nums:
    
    