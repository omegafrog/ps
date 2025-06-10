N, M = list(map(int, input().rstrip().split()))
nums = list(map(int, input().rstrip().split()))

nums.sort()

res = [0] * (M)

aSet = set()


def select(idx, numIdx):
    if idx >= M:
        arrStr = ""
        for num in res:
            arrStr = arrStr + str(num) + " "
        if arrStr not in aSet:
            print(arrStr)
            aSet.add(arrStr)
        return

    for i in range(numIdx, len(nums)):
        res[idx] = nums[i]
        select(idx + 1, i)


select(0, 0)
