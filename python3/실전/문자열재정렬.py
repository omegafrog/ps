inputs = input()

sums = 0
alphabets = []
for c in inputs:
    if 'A'<= c and c <= 'Z':
        alphabets.append(c)
    else:
        sums+=int(c)

sortedAlpha = sorted(alphabets)
for c in sortedAlpha:
    print(c, end="")
print(sums)
