## 57 :00 / 30:00
## 풀음

## recursive 함수를 작성하는데 시간이 너무 오래 걸렸음.for문을 돌리는데 내부에서 return을 때려버리니까 모든 경우의 수를 다 안돌아서
## 이것때문에 한번

## 두번째로는 python의 파라미터로 minVal, maxVal을 넘겨주었는데 이게 반영이 안됨;
## 그래서 리턴값을 주도록 변경했는데 여기서 시간 소모가 늘어남
import sys


def recursive(nums, pos, plus, minus, times, divide, result, minVal, maxVal):
    if plus == 0 and minus == 0 and times == 0 and divide == 0:
        print(result, minVal, maxVal)
        minVal = min(result, minVal)
        maxVal = max(result, maxVal)
        return [minVal, maxVal]

    for oprator in range(4):
        if oprator == 0 and plus > 0:
            res = recursive(
                nums,
                pos + 1,
                plus - 1,
                minus,
                times,
                divide,
                result + nums[pos],
                minVal,
                maxVal,
            )
            minVal = min(minVal, res[0])
            maxVal = max(maxVal, res[1])

        elif oprator == 1 and minus > 0:
            res = recursive(
                nums,
                pos + 1,
                plus,
                minus - 1,
                times,
                divide,
                result - nums[pos],
                minVal,
                maxVal,
            )
            minVal = min(minVal, res[0])
            maxVal = max(maxVal, res[1])
        elif oprator == 2 and times > 0:
            res = recursive(
                nums,
                pos + 1,
                plus,
                minus,
                times - 1,
                divide,
                result * nums[pos],
                minVal,
                maxVal,
            )
            minVal = min(minVal, res[0])
            maxVal = max(maxVal, res[1])
        elif oprator == 3 and divide > 0:
            if result < 0:
                result = result * (-1)
                result = result // nums[pos]
                result = result * (-1)
            elif nums[pos] < 0:
                result = result // ((-1) * nums[pos])
                result = result * (-1)
            else:
                result = result // nums[pos]
            res = recursive(
                nums, pos + 1, plus, minus, times, divide - 1, result, minVal, maxVal
            )
            minVal = min(minVal, res[0])
            maxVal = max(maxVal, res[1])

    return [minVal, maxVal]


N = int(input())

nums = list(map(int, sys.stdin.readline().rstrip().split()))

plus, minus, times, divide = map(int, sys.stdin.readline().rstrip().split())

maxVal = -1000000000
minVal = 1000000000

minRes, maxRes = recursive(nums, 1, plus, minus, times, divide, nums[0], minVal, maxVal)

print(minRes)
print(maxRes)
