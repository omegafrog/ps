## 24:56 / 20:00
## 풀음
## 스택으로 괄호 판단하는거를 검증하는데 시간이 좀 걸리고
## python 문자열을 변경불가능하다는 것을 아랏습니다
def divide(p):
    leftCnt = 0
    rightCnt = 0
    for i in range(len(p)):
        word = p[i]
        if word == "(":
            leftCnt = leftCnt + 1
        if word == ")":
            rightCnt = rightCnt + 1
        if leftCnt == rightCnt:
            return [p[: i + 1], p[i + 1 :]]


def isCorrectStr(p):
    s = []
    for word in p:
        if word == "(":
            s.append(word)
        elif word == ")":
            if len(s) == 0:
                return False
            s.pop()
    return len(s) == 0


def solution(p):
    if len(p) == 0:
        return p
    if isCorrectStr(p):
        return p

    u, v = divide(p)
    # print(u,v)

    if isCorrectStr(u):
        # print("correct")
        return u + solution(v)
    else:
        tmp = "("
        tmp = tmp + solution(v)
        tmp = tmp + ")"

        u = u[1:-1]
        changedU = ""
        for i in range(len(u)):
            word = u[i]
            if word == "(":
                changedU += ")"
            else:
                changedU += "("

        tmp = tmp + changedU
        # print("tmp:", tmp)
        return tmp
