# 밟은 알파벳 셋을 가지고 판단하면됨
# 한 칸을 그래프 노드로 보고 큐로 bfs처럼
# 1. 큐에서 1개 꺼냄. 이때 큐에는 [ 지난 거리, 현재 좌표]
# 2. 현재 좌표에서 인접 칸들을 순회
# 3. 칸들 중에서 알파벳 셋에 없는 애들 선택
# 4. [지난 거리 + 1, 인접 좌표] 로 큐에 다시 넣음.
# 5. 거리 최댓값을 max( 지난 거리+1, 기존 최대값)으로 업데이트

# R : 세로 C : 가로
from collections import deque

R, C = list(map(int, input().rstrip().split()))

board = []
diffs = [[-1, 0], [0, -1], [1, 0], [0, 1]]

for _ in range(R):
    board.append(list(input()))

# print(board)
alphaSet = set(board[0][0])

q = []
q.append([1, 0, 0, alphaSet])

maxLen = 1


# while len(q) > 0:
#     curLen, curY, curX, curSet = q.pop()
#     for diff in diffs:
#         nextY = curY + diff[0]
#         nextX = curX + diff[1]
#         if 0 <= nextY and nextY < R and 0 <= nextX and nextX < C:
#             if board[nextY][nextX] not in curSet:
#                 tmpSet = set(curSet)
#                 tmpSet.add(board[nextY][nextX])
#                 q.append([curLen + 1, nextY, nextX, tmpSet])
#                 maxLen = max(maxLen, curLen + 1)


def backTracking(y, x, curSet, board):
    nextLen = 0
    for diff in diffs:
        nextY = y + diff[0]
        nextX = x + diff[1]
        if 0 <= nextY and nextY < R and 0 <= nextX and nextX < C:
            if board[nextY][nextX] not in curSet:
                curSet.add(board[nextY][nextX])
                nextLen = max(nextLen, backTracking(nextY, nextX, curSet, board))
                curSet.remove(board[nextY][nextX])
    return nextLen + 1


res = backTracking(0, 0, set(board[0][0]), board)

print(res)
