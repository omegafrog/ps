import sys
from collections import deque

"""
   아래의 stdin 함수는 sample_input.txt 를 read only 형식으로 연 후,
   앞으로 표준 입력(키보드) 대신 sample_input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
   여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 sample_input.txt에 입력을 저장한 후,
   stdin 함수를 이용하면 이후 input 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
   단, 채점을 위해 코드를 제출하실 때에는 반드시 stdin 함수를 지우거나 주석 처리 하셔야 합니다.
"""
# sys.stdin = open('Sample_input.txt', 'r')


"""
  여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
"""

T = int(input())
for test_case in range(1, T + 1):
    N, K = list(map(int, input().rstrip().split()))
    inputs = list(map(int, input().rstrip().split()))
    res_list = []
    cnt = 0
    q = deque(inputs)
    res_list.append(list(q))
    while True:
        check = q[0]
        flag = False
        ## 모든 값이 같은지 확인
        for i in q:
            if check != i:
                flag = True
                break
        if flag == False:
            print("#%d %d" % (test_case, cnt))
            break

        # 작업 진행
        tmp = q[K - 1]
        q.append(tmp)
        q.popleft()
        cnt = cnt + 1

        ## 작업 결과중 루프 확인
        roopFlag = False
        for res in res_list:
            if res == list(q):
                # print(res, q)
                # print(inputs)
                # print(q)
                # print(res_list)
                print("#%d %d" % (test_case, -1))
                roopFlag = True
                break
        if roopFlag:
            break

        ## 작업 결과 저장
        res_list.append(list(q))

    #######################################################################################################
    #'''
    #  이 부분에 여러분의 알고리즘 구현이 들어갑니다.
    #'''
    #######################################################################################################

    # 표준출력(화면)으로 답안을 출력합니다.

