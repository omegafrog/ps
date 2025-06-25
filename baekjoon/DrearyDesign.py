T = int(input())
for case in range(1, T + 1):
    K, V = map(int, input().split())
    cnt = 0

    for r in range(0, K + 1):
        for g in range(0, K + 1):
            # r–g 차이부터 빠르게 걸러내고
            if abs(r - g) > V:
                continue
            for b in range(0, K + 1):
                # 나머지 두 쌍 모두 검사
                if abs(r - b) <= V and abs(g - b) <= V:
                    cnt += 1

    print(f"Case #{case}: {cnt}")
