T = int(input())

for _ in range(T):
    N = int(input())

    selected = list(map(int, input().rstrip().split()))
    selectTeam = [0] * (N + 1)

    edges = [[] for _ in range(N + 1)]
    for i in range(len(selected)):
        edges[i + 1].append(selected[i])

    s = []
    visited = [0] * (N + 1)
    for i in range(len(selected)):
        if i + 1 == selected[i]:
            selectTeam[i + 1] = 1
            visited[i + 1] = 1

    print(visited)
    for i in range(1, N):
        if visited[i] == 1:
            continue
        s.append([i, []])
        visited[i] = 1
        for i in range(5):
            print(s)
            cur, selectList = s.pop()
            idx = 0
            try:
                idx = selectList.index(cur)
            except ValueError:
                idx = -1
            print(idx)

            if idx >= 0:
                for i in range(idx, len(selectList)):
                    selectTeam[i] = 1
                break

            for adj in edges[cur]:
                newList = list(selectList)
                newList.append(adj)
                s.append([adj, newList])

    cnt = 0
    for i in selectTeam:
        if i == 0:
            cnt += 1
    print(cnt)
