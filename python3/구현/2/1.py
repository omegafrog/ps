
a = str(input())
# y x 

cur = [int(a[1]),ord(a[0])-ord('a')+1]

dirs = [[2,1],[2,-1],[1,2],[-1,2],[-2,1],[-2,-1],[1,-2],[-1,-2]]
cnt = 0
for direction in dirs:
    nextDir = [cur[0]+direction[0],cur[1]+direction[1]]
    print(nextDir)
    if 0 < nextDir[0] and nextDir[0] <=8 and 0 < nextDir[1] and nextDir[1] <=8:
       cnt+=1

print(cnt) 
