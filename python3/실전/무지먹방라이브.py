import heapq
def solution(food_times, k):
    answer = 0
    if sum(food_times)<=k:
        return -1
    h = []
    for i in range(len(food_times)):
        heapq.heappush(h, (food_times[i], i))
    before = 0
    while k >= len(h)*(h[0][0]-before):
        curLen = len(h)
        cur = heapq.heappop(h)
        k -= curLen*(cur[0]-before)
        before=cur[0]
    
    sortedH = sorted(h, key= lambda x: x[1])
    answer = sortedH[k%len(sortedH)][1]+1
    return answer