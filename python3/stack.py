import sys

class stack:
    def __init__(self):
        self.data = [0]*10000
        self.top=-1
    def push(self,x):
        self.top+=1
        self.data[self.top]=x
    def pop(self):
        if(self.empty()):
            return -1
        res = self.data[self.top]
        self.top-=1
        return res
    def size(self):
        return self.top+1
    def empty(self):
        return self.size()==0
    
    def Top(self):
        if self.empty() : return -1
        return self.data[self.top]

s=stack()

cnt=int(sys.stdin.readline())
for i in range(cnt):
    cmdline=sys.stdin.readline().rstrip().split(" ")
    cmd=cmdline[0]
    arg=0
    if len(cmdline)>1:
        arg=int(cmdline[1])
    if cmd=="push":
        s.push(arg)
    elif cmd=="pop":
        print(s.pop())
    elif cmd=="top":
        print(s.Top())
    elif cmd=="size":
        print(s.size())
    elif cmd=="empty":
        res = 1 if s.empty() else 0
        print(res)



    
    
    

