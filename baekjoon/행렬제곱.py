import sys

N, B = list(map(int, input().rstrip().split()))

mat = []

for y in range(N):
    mat.append(list(map(int, sys.stdin.readline().rstrip().split())))


def matMul(mat1, mat2):
    res = [[0] * len(mat1) for _ in range(len(mat1))]
    for i in range(len(mat1)):
        for j in range(len(mat2)):
            for n in range(len(mat1)):
                res[i][j] = (res[i][j] + mat1[i][n] * mat2[n][j]) % 1000
    return res


def divide(
    mat,
    n,
):
    print(n)
    if n == 1:
        return [[elem % 1000 for elem in row] for row in mat]

    tmp = divide(mat, n // 2)
    if n % 2 == 0:
        return matMul(tmp, tmp)
    else:
        return matMul(matMul(mat, tmp), tmp)


res = divide(mat, B)
for i in range(N):
    for j in range(N):
        print(res[i][j], end=" ")
    print()
