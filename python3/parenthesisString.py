import sys;

tcase=int(input())

for case in range(tcase):
    sentence = sys.stdin.readline().rstrip()
    stack = []
    successFlag = True
    for i in range(len(sentence)):
        word = sentence[i]
        if word == '(':
            stack.append(word)
        elif word==')':
            if len(stack) ==0:
                successFlag=False
                break
            else :
                stack.pop()

    if successFlag == False or len(stack)>0 :
        print("NO")
    else:
        print("YES")
        
        