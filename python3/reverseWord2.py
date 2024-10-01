class stack:
    def __init__(self):
        self.capacity = 100000
        self.data = [""]*self.capacity
        self.top = -1
        self.size = 0

    def push(self, x):

        self.top += 1
        self.data[self.top] = x
        self.size += 1

    def pop(self):
        res = self.data[self.top]
        self.top -= 1
        self.size -= 1
        return res

    def Size(self):
        return self.size

    def empty(self):
        if self.size == 0:
            return 1
        else:
            return 0


s = input()
sentence = []
for i in range(len(s)):
    sentence.append(s[i])


isTag = False
startIdx = -1
wordStack = stack()

for i in range(len(s)):
    if s[i] == '<':
        for idx in range(startIdx, startIdx+wordStack.Size()):
            sentence[idx] = wordStack.pop()
        startIdx = -1
        isTag = True
        continue

    if s[i] == '>':
        isTag = False
        continue

    if isTag:
        continue
    else:
        if startIdx == -1:
            startIdx = i
            wordStack = stack()
            wordStack.push(s[i])
            continue
        else:
            if s[i] == " ":
                for idx in range(startIdx, startIdx+wordStack.Size()):
                    sentence[idx] = wordStack.pop()
                startIdx = -1
            else:
                wordStack.push(s[i])
if wordStack.empty() == 0:
    for idx in range(startIdx, startIdx+wordStack.Size()):
        sentence[idx] = wordStack.pop()


for i in sentence:
    print(i, end="")
