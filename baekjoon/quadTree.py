import sys
# 1111 0000 1111 0000
# 1111 0000 1111 0000
# 1111 0000 1111 0000
# 1111 0000 1111 0000
#
# 0000 1111 0000 1111
# 0000 1111 0000 1111
# 0000 1111 0000 1111
# 0000 1111 0000 1111
#
# 1111 0000 1111 0000
# 1111 0000 1111 0000
# 1111 0000 1111 0000
# 1111 0000 1111 0000
#
# 0000 1111 0000 1111
# 0000 1111 0000 1111
# 0000 1111 0000 1111
# 0000 1111 0000 1111
#
# WBWB
# BWBW
# WBWB
# BWBW
#
# QWBBWQWBBWQWBBWQWBBW
#
# 512 -> 2^9 -> depth = 9


def divideboard(y, x, length, board):
    if length == 1:
        if board[y][x] == 1:
            return "B"
        else:
            return "W"
    res = ""
    pivot = board[y][x]
    for dy in range(length):
        for dx in range(length):
            if board[y + dy][x + dx] != pivot:
                dividelength = length // 2
                res1 = divideboard(y, x, length // 2, board)
                res2 = divideboard(y, x + dividelength, length // 2, board)
                res3 = divideboard(y + dividelength, x, length // 2, board)
                res4 = divideboard(
                    y + dividelength, x + dividelength, length // 2, board
                )
                res += "Q" + res1 + res2 + res3 + res4
                return res
    if pivot == 1:
        return "B"
    else:
        return "W"


def toDigit(num):
    res = []
    while num > 1:
        res.append(num % 2)
        num = num // 2
    res.append(num)
    while len(res) < 4:
        res.append(0)
    res.reverse()
    return res


N = int(input().split()[2])
input()
input()
board = []
for i in range(N):
    inputLine = sys.stdin.readline()
    if inputLine != "};":
        hexs = list(inputLine.rstrip().split(","))
        tmp = []
        for num in hexs:
            if num == "":
                continue
            num = num[2:]
            num = list(num)
            num.reverse()
            for char in num:
                if char.isalpha():
                    digits = toDigit(ord(char) - ord("a") + 10)
                else:
                    digits = toDigit(int(char))
                digits.reverse()
                tmp = tmp + digits
        board.append(tmp)
print(N)
print(divideboard(0, 0, N, board))

