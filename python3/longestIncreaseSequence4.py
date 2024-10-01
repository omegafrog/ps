import sys

n = int(input())

a = list(map(int, sys.stdin.readline().rstrip().split(" ")))

mem = []

for i in range(n):
    mem.append({"size": -1, "arr": []})


def calc(start, n, mem):

    if mem[start]["size"] != -1:
        return mem[start]

    res = {"size": 0, "arr": []}

    for i in range(start+1, n):
        if a[i] > a[start]:
            cand = calc(i, n, mem)
            if res.get("size") < cand.get("size"):
                res = cand

    mem[start]["arr"] = res["arr"][:]
    mem[start]["arr"].append(a[start])
    mem[start]["size"] = len(mem[start]["arr"])
    return mem[start]


for i in range(n):
    calc(i, n, mem)

res = {"size": -1, "arr": []}

for i in range(n):
    if res["size"] < mem[i]["size"]:
        res = mem[i]

print(res["size"])

for num in reversed(res["arr"]):
    print(num, end=" ")
