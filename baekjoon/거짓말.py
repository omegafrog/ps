# 17: 14 ~
#
# 과장된 이야기 할 수 있는 조건
# 진실을 아는 사람이 포함된 경우 불가능
# 진실을 말한 사람에게 거짓말 못함
#
# 먼저 진실을 말한 사람이 포함된 파티 찾음 ->
# 입력으로 받은 파티에 맵을 다 넣어 N개 버킷있는
# 그다음에 입력 받으면서 파티에 있으면 값을 1
# 그리고 진실 아는 사람 순회 돌리면서
# 모든 파티를 순회 돌리면서 사람 번호가 파티에 있는지 맵으로 검색
# 있으면 제외, 없으면 세기
# 4 1
# 1 1
# 4 1 2 3 4
#
# 4
# 1 2 3
# 3 4 5
# from collections import deque
#
# N, M = list(map(int, input().rstrip().split()))
# truthInput = list(map(int, input().rstrip().split()))
# numOfTruth = truthInput[0]
# truths = truthInput[1:]
# truths = set(truths)
#
# parties = deque([])
# contains = deque([])
#
#
# for i in range(M):
#     flag = False
#     arr = list(map(int, input().rstrip().split()))[1:]
#     tmp = {}
#     for num in arr:
#         tmp[num] = 1
#         if num in truths:
#             flag = True
#
#     if flag:
#         parties.appendleft(arr)
#         contains.appendleft(tmp)
#     else:
#         parties.append(arr)
#         contains.append(tmp)
#
# # print(parties)
# # print(contains)
#
# cnt = 0
# for i in range(M):
#     truthFlag = 0
#     for truth in truths:
#         if truth in contains[i] and contains[i][truth] == 1:
#             for people in parties[i]:
#                 truths.add(people)
#             truthFlag = 1
#             break
#     if truthFlag != 1:
#         cnt += 1
#
# # print(truths)
# print(cnt)
#


def find(a, parent):
    if a != parent[a]:
        return find(parent[a], parent)
    else:
        return a


def union(a, b, parent):
    parentA = find(a, parent)
    parentB = find(b, parent)
    if parentA < parentB:
        parent[parentB] = parentA
    else:
        parent[parentA] = parentB


N, M = list(map(int, input().rstrip().split()))
truthInput = list(map(int, input().rstrip().split()))
truths = truthInput[1:]

parent = [x for x in range(N + 1)]
parties = []

for i in range(M):
    arr = list(map(int, input().rstrip().split()))[1:]
    for num in arr:
        union(arr[0], num, parent)
    parties.append(arr)

cnt = 0

for party in parties:
    flag = False
    for truth in truths:
        parentTruth = find(truth, parent)
        parentPeople = find(party[0], parent)
        if parentTruth == parentPeople:
            flag = True
            break
    if not flag:
        cnt += 1

# print(parent)

print(cnt)
