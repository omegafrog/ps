# 다양한 수로 이루어진 배열ㅇ ㅣ있을 때 주어진 수들을 M번 더해 가장 큰 수를 만들어라
# 이때 배열의 특정 인덱스에 해당하는 수가 연속해서 K번 초과해 더할 수 없다.

# 2<= N <= 1000 1<= M <= 10000, 1<=K <=10000
# 첫째 줄에 N, M, K가 주어진다
# 둘째 줄에 N개의 자여수가 주어진다
# K<=M
import sys;

string = sys.stdin.readline().rstrip().split(" ")

N = int(string[0])
M = int(string[1])
K = int(string[2])

numbers = list(map(int, sys.stdin.readline().rstrip().split(" ")))
print(N, M, K, numbers)
numbers.sort(reverse=True)

res = 0
idx = 0
i = 0
while i < M:
    for j in range(K):
        res+=numbers[0]
        i+=1
    res+=numbers[1]
    i+=1

print(res)