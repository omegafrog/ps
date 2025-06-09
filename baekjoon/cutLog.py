N, M = list(map(int, input().split(" ")))
trees = list(map(int, input().split(" ")))

start = 0
end = 1000000000


res = 0

if M == 0:
    print(end)
    exit(0)

while start < end:
    mid = (end + start) // 2

    totalLength = 0
    for tree in trees:
        length = tree - mid
        if length > 0:
            totalLength += length

    if totalLength > M:
        if res < mid:
            res = mid
        start = mid + 1
    elif totalLength == M:
        print(mid)
        exit(0)
    else:
        end = mid

print(res)
