numstr = input()

numlen = len(numstr)

idx = 0

numsum1 = 0
numsum2 = 0
while idx < numlen//2:
    numsum1 += int(numstr[idx])
    idx+=1

while idx < numlen:
    numsum2 += int(numstr[idx])
    idx+=1

if numsum1==numsum2:
    print("LUCKY")
else:
    print("READY")

