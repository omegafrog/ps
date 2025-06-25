T = int(input())

for i in range(T):
    N = int(input())
    inputs = list(map(int, input().rstrip().split()))
    inputs.sort()
    res = 0
    idx = 0
    for j in range(1, len(inputs) + 1):
        flag = False
        for k in range(idx, len(inputs)):
            if j <= inputs[k]:
                flag = True
                idx = k + 1
                break

        if not flag:
            break
        res = j
    print("Case #{}: {}".format(i + 1, res))
