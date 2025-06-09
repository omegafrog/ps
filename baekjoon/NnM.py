N, M = list(map(int, input().split(" ")))

nums = list(map(int, input().split(" ")))


nums.sort()


def find(deps, selected, nums, M):
    if deps == M:
        for i in range(len(selected)):
            if i < len(selected) - 1:
                print(selected[i], end=" ")
            else:
                print(selected[i])
        return
    else:
        before = -1
        for i in range(len(nums)):
            if before == nums[i]:
                continue
            tmp = nums[i]
            selected.append(nums[i])
            del nums[i]
            find(deps + 1, selected, nums, M)
            selected.pop()
            nums.insert(i, tmp)
            before = nums[i]


find(0, [], nums, M)
