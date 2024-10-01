class Stack:
    def __init__(self):
        self.capacity = 100000
        self.data = [-1]*100000
        self.size = 0
        self.top = -1

    def push(self, x):
        self.top += 1
        self.data[self.top] = x
        self.size += 1

    def pop(self):
        res = self.data[self.top]
        self.top -= 1
        self.size -= 1
        return res

    def empty(self):
        if self.size > 0:
            return 0
        else:
            return 1

    def update(self, cnt):
        if self.empty() == 1:
            return -1

        for i in range(self.size):
            self.data[i] += cnt


s = input()
res = 0
st = Stack()
lazorCnt = 0
isStart = False
i = 0
while True:
    if i >= len(s):
        break
    if s[i] == "(":
        if s[i+1] == ")":
            if st.empty() == 0:
                st.data[st.top] += 1
            i += 2
            continue
        else:
            st.push(0)
    else:
        tmp = st.pop()
        res += tmp+1
        st.data[st.top] += tmp

    i += 1
print(res)
