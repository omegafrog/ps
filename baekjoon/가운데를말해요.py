# 문제
# 백준이는 동생에게 "가운데를 말해요" 게임을 가르쳐주고 있다.
# 백준이가 정수를 하나씩 외칠때마다 동생은 지금까지 백준이가 말한 수 중에서 중간값을 말해야 한다.
# 만약, 그동안 백준이가 외친 수의 개수가 짝수개라면 중간에 있는 두 수 중에서 작은 수를 말해야 한다.
#
# 예를 들어 백준이가 동생에게 1, 5, 2, 10, -99, 7, 5를 순서대로 외쳤다고 하면, 동생은 1, 1, 2, 2, 2, 2, 5를 차례대로 말해야 한다.
# 백준이가 외치는 수가 주어졌을 때, 동생이 말해야 하는 수를 구하는 프로그램을 작성하시오.
#
# 입력
# 첫째 줄에는 백준이가 외치는 정수의 개수 N이 주어진다. N은 1보다 크거나 같고, 100,000보다 작거나 같은 자연수이다.
# 그 다음 N줄에 걸쳐서 백준이가 외치는 정수가 차례대로 주어진다. 정수는 -10,000보다 크거나 같고, 10,000보다 작거나 같다.
#
# 출력
# 한 줄에 하나씩 N줄에 걸쳐 백준이의 동생이 말해야 하는 수를 순서대로 출력한다.

# 1. 브루트포스
# 배열에 백준이가 부를 때마다 다 넣고 정렬해서 중간값 찾기 -> nlgn * N 번 : 불가능
# n의 범위가 20000개니까 20000개 배열 만들어서 1개씩 넣기
# 그리고 매번 20000번 배열 순회해서 중간값 찾기
#
# 2. 힙 사용
# 중간값을 a라고 하면, a보다 작은 값들과 a보다 큰 값들로 나눌 수 있음.
# 이때 작은 값들을 leftHeap, 큰값들을 rightHeap
# 그리고 leftHeap의 루트가 중간값이라고 하자.
# 왼쪽이 1개 더많도록 조정하면됨.

import sys
import heapq

T = int(input())

leftHeap = []
rightHeap = []
for i in range(T):
    tmp = int(sys.stdin.readline().rstrip())

    if i == 0:
        heapq.heappush(leftHeap, (-1 * tmp, tmp))
        print(leftHeap[0][1])
        continue

    leftTop = leftHeap[0][0] * -1

    if tmp <= leftTop:
        heapq.heappush(leftHeap, (-1 * tmp, tmp))
    else:
        heapq.heappush(rightHeap, (tmp, tmp))

    leftSize = len(leftHeap)
    rightSize = len(rightHeap)

    # print(leftSize, rightSize)
    # print(i, leftHeap, rightHeap)
    if leftSize < rightSize:
        while len(leftHeap) < len(rightHeap):
            key, val = heapq.heappop(rightHeap)
            heapq.heappush(leftHeap, (-1 * key, val))
    if leftSize - rightSize > 1:
        while len(leftHeap) - len(rightHeap) > 1:
            key, val = heapq.heappop(leftHeap)
            heapq.heappush(rightHeap, (-1 * key, val))

    print(leftHeap[0][1])
