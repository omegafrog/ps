N = int(input())
# print(N)

K = 1000000007


def matMul(a, b):
    res = [[0] * len(b[0]) for _ in range(len(a))]
    for y in range(len(a)):
        for x in range(len(b[0])):
            for i in range(len(b[0])):
                res[y][x] += a[y][i] * b[i][x] % K

    return res


def divideNConqure(N):
    if N == 1:
        return [[1, 1], [1, 0]]
    elif N == 0:
        return [[1, 0], [0, 1]]

    res = divideNConqure(N // 2)
    if N % 2 == 0:
        return matMul(res, res)
    else:
        return matMul(matMul(res, res), [[1, 1], [1, 0]])


res = divideNConqure(N - 1)

res = matMul(res, [[1], [0]])
print(res[0][0])
