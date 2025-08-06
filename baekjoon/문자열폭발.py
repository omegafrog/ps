# 문자열 길이 1,000,000
# 폭탄문자열길이가 1이라고 하면, 폭발 한번 일어나면 n-1
# 이렇게 되면 최악의 경우 depth가 1000000번
# 흠...
# depth 한번마다 문자열을 전부 순회해서 폭탄문자열을 찾아야 하는데
# 그리고 자르고 나머지를 붙이면 새로운 문자열을 생성하니까 흠
# 비트마스킹 같은걸로 해결이 가능할지도 모르겟다

inputstr = list(input())
bomb = input()

stack = []
for char in inputstr:
    if len(stack) >= len(bomb):
        tmp = stack[-1 * len(bomb) :]
        # print(tmp, bomb, tmp == bomb)
        if tmp == list(bomb):
            for _ in range(len(bomb)):
                stack.pop()

    stack.append(char)

if len(stack) >= len(bomb):
    tmp = stack[-1 * len(bomb) :]
    # print(tmp, bomb, tmp == bomb)
    if tmp == list(bomb):
        for _ in range(len(bomb)):
            stack.pop()


if len(stack) == 0:
    print("FRULA")
else:
    for char in stack:
        print(char, end="")
