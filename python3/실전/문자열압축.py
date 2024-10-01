# 문자열을 "처음부터" n개 단위로 끊어서 압축한다는 것을 인지
# 1개부터 n개까지의 길이로 자르는 횟수가 n번
# 그 길이에 따라서 s를 자르는 횟수도 최대 n번
# 그러므로 O(N^2) 번이라고 ㅍ판단, n이 1000이므로 충분히 가능
# 압축할 기준을 저장해 놓고 순회를 돌리면서 기준과 현재 잘린 문자가 같은지 비교
# 같다면 카운트를 1 올리고 다음으로 진행
# 다르다면
# 만약 카운트가 1이라면 그냥 기준을 결과 문자열에 추가
# 카운트가 1 이상이라면 카운트 + 기준 문자열 을 결과 문자열에 추가
# 이후 카운트를 초기화하고 기준 문자열을 잘린 문자로 변경
# 이러면 마지막 압축 문자열은 안들어가므로 마지막 압축문자열 추가해줌
# 문자열압축이 끝나면 길일르 비교해서 최소 길이 갱신

def solution(s):
    answer = 0
    shortest = 987654321
    if len(s) == 1: return 1
    for i in range(1, len(s)):
        comp = s[0:i]
        compCnt = 0
        compressed = ""
        for idx in range(0, len(s), i):
            cur = s[idx:idx+i]
            # print("cur:",cur, compCnt)
            if comp == cur:
                compCnt+=1
            else:
                if compCnt == 1:
                    compressed+=comp
                else:
                    compressed+=str(compCnt)+comp
                comp = cur
                compCnt=1
        
        if compCnt == 1:
            compressed+=comp
        else:
            compressed+=str(compCnt)+comp
        comp = cur
        compCnt=1
        
        # print(i, compressed)
        shortest = min(shortest, len(compressed))
    
    answer = shortest
        
    return answer