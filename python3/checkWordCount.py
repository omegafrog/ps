
s = input()

dict = {}

for i in list(map(chr, range(ord('a'), ord('z')+1))):
    dict[i] = 0
for w in s:
    dict[w] += 1

for i in list(map(chr, range(ord('a'), ord('z')+1))):
    print(dict[i], end=" ")
