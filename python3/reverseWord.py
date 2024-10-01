import sys;

T = int(sys.stdin.readline().rstrip())

for tCase in range(T):
    sentence = sys.stdin.readline().rstrip().split(" ")
    for i in range(len(sentence)):
        for j in range(len(sentence[i])-1, -1, -1):
            print(sentence[i][j],end="")
        if i<len(sentence)-1:
            print(" ",end="")
        else: print()
        
