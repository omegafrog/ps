N = int(input())

board = [-1] * N


def recur(y):
    res = 0
    if y == N:
        return 1
    for j in range(N):
        flag = False

        for tmp in range(y):
            if j == board[tmp]:
                flag = True
                break
            if board[tmp] > -1 and abs(y - tmp) == abs(j - board[tmp]):
                flag = True
                break
        if flag:
            continue
        board[y] = j
        res += recur(y + 1)
        board[y] = -1
    return res


print(recur(0))
