import sys;

seqLen = int(input())
seq=[]
for i in range(seqLen):
    seq.append(int(input()))

stack = []
res = []
flag = True
i = 1
for wanted in seq:
    if len(stack) == 0 :
        if i > seqLen:
            print("NO")
            flag=False
            break
        stack.append(i)
        res.append("+")
        i+=1
    
    top = stack[-1]

    if  top < wanted:
        while top < wanted :
            stack.append(i)
            top = i
            i+=1
            res.append("+")
        stack.pop()
        res.append("-")
    elif top == wanted:
        stack.pop()
        res.append("-")
    elif top > wanted:
        print("NO")
        flag=False
        break

if flag == True:
    for i in res:
        print(i)
            


    
        
            
        


    