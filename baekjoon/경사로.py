import sys

N, L = list(map(int, input().rstrip().split()))

data = []
for _ in range(N):
    data.append(list(map(int, sys.stdin.readline().rstrip().split())))

cnt = 0
for y in range(N):
    # print(data[y])
    start = 0
    startHeight = data[y][start]
    canCross = True
    space = [0] * (N)
    x = 0
    while x < N:
        # 오르막경사 필요
        if startHeight + 1 == data[y][x]:
            slideStart = x - L
            slideEnd = x
            # 경사로 놓을 공간 부족
            if slideStart < 0:
                # print("경사로 놓을 공간 부족")
                canCross = False
                break

            lowHeight = data[y][slideStart]
            for idx in range(slideStart, slideEnd):
                if data[y][idx] != lowHeight or space[idx] == 1:
                    # print("경사로 놓을 자리 안평평")
                    canCross = False
                    break
                space[idx] = 1
            startHeight = data[y][slideEnd]

        # 내리막경사 필요
        elif startHeight - 1 == data[y][x]:
            slideStart = x
            slideEnd = x + L - 1
            if slideEnd >= N:
                # print("경사로 공간부족")
                canCross = False
                break
            highHeight = data[y][slideStart]
            for idx in range(slideStart, slideEnd + 1):
                if data[y][idx] != highHeight or space[idx] == 1:
                    canCross = False
                    break
                space[idx] = 1
            startHeight = data[y][slideStart]
        elif abs(startHeight - data[y][x]) > 1:
            # print("높이차2이상")
            canCross = False
            break
        else:
            x += 1

    if canCross:
        cnt += 1
for x in range(N):
    # for tmp in range(N):
    #     print(data[tmp][x], end=" ")
    # print()
    start = 0
    startHeight = data[0][x]
    canCross = True
    space = [0] * (N)
    y = 0
    while y < N:
        # 오르막경사 필요
        if startHeight + 1 == data[y][x]:
            # print("오르막경사 필요")
            slideStart = y - L
            slideEnd = y
            # 경사로 놓을 공간 부족
            if slideStart < 0:
                # print("경사로 놓을 공간 부족")
                canCross = False
                break

            lowHeight = data[slideStart][x]
            for idx in range(slideStart, slideEnd):
                if data[idx][x] != lowHeight or space[idx] == 1:
                    # print("경사로 놓을 자리 안평평")
                    canCross = False
                    break
                space[idx] = 1
            startHeight = data[slideEnd][x]

        # 내리막경사 필요
        elif startHeight - 1 == data[y][x]:
            # print("내리막경사 필요")
            slideStart = y
            slideEnd = y + L - 1
            if slideEnd >= N:
                # print("경사로 공간부족")
                canCross = False
                break
            highHeight = data[slideStart][x]
            for idx in range(slideStart, slideEnd + 1):
                if data[idx][x] != highHeight or space[idx] == 1:
                    # print("경사로 공간부족")
                    canCross = False
                    break
                space[idx] = 1
            if not canCross:
                break
            startHeight = data[slideStart][x]
        elif abs(startHeight - data[y][x]) > 1:
            # print("높이차2이상")
            canCross = False
            break
        else:
            y += 1

    if canCross:
        cnt += 1
print(cnt)
