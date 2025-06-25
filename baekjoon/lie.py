N, M = list(map(int, input().rstrip().split()))

parents = [-1] * (N + 1)

cnt = 0
inputs= []

def selectOne(idx, parents, inputs):



for _ in range(M):
    inputs.append( list(map(int, input().rstrip().split())))
    if len(inputs) == 1:
      cnt+=1  
    else:
        for _ in range(inputs[0]):



def find(a):
    if parents[a] == a:
        return a
    return find(parents[a])


def union(a, b):
    parentA = find(a)
    parentB = find(b)
    if parentA != parentB:
        parents[parentB] = parentA
