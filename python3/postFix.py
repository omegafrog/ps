import sys

n = int(input())

cmd = sys.stdin.readline().rstrip()

args = {}
i = 0

for alphabet in list(map(chr, range(ord('A'), ord('Z')+1))):
    if i >= n:
        break
    args[alphabet] = int(sys.stdin.readline().rstrip())
    i += 1

stack = []


for w in cmd:
    if w >= "A" and w <= "Z":
        stack.append(args[w])
        continue
    else:
        rightArg = stack.pop()
        leftArg = stack.pop()
        res = 0
        if w == "*":
            res = leftArg*rightArg
        elif w == "/":
            res = leftArg/rightArg
        elif w == "+":
            res = leftArg+rightArg
        elif w == "-":
            res = leftArg-rightArg
        stack.append(res)

print("{:.2f}".format(stack[-1]))
