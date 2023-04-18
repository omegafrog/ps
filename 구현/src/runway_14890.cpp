#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    int L;
    cin >> N >> L;
    int **input = (int **)malloc(sizeof(int *) * N);
    for (int i = 0; i < N; i++)
    {
        input[i] = (int *)malloc(sizeof(int) * N);
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> input[i][j];
        }
    }
    int **runway = (int **)malloc(sizeof(int *) * N);
    for (int i = 0; i < N; i++)
    {
        runway[i] = (int *)malloc(sizeof(int) * N);
    }
    vector<pair<int, int>> runwayList;
    int res = 0;
    bool isFlatted = true;
    bool canPassLeft = true;
    for (int y = 0; y < N; y++)
    {
        canPassLeft = true;
        isFlatted = true;
        for (int x = 0; x < N - 1; x++)
        {

            int nextX = x + 1;
            int height = input[y][x];
            int nextHeight = input[y][nextX];
            // 높이가 다른 칸을 만나는지 체크
            // 높이가 다른 칸을 만나면 경사로를 놓을 수 있는지 체크
            // 1. 높이차가 1이어야 함
            // 2. 높이차가 1인 칸이 L 길이만큼 지속되어야 함
            // 3. L 길이의 경사로를 놓을 때 범위를 벗어나지 않아야 함.
            // 4. 경사로를 놓을 때 경사로가 있는지 체크해야 함.
            // 높이차 체크
            if (nextHeight - height == -1)
            {
                isFlatted = false;
                // 범위 체크
                if (x + L < N)
                {
                    bool canLetRunway = true;
                    // 경사로 놓을 수 있는지 체크
                    for (int i = 0; i < L; i++)
                    {
                        // L길이의 높이차 체크
                        if (input[y][nextX + i] != nextHeight)
                        {
                            canLetRunway = false;
                            break;
                        }
                        // 경사로 체크
                        if (runway[y][nextX + i] != 0)
                        {
                            canLetRunway = false;
                            break;
                        }
                    }
                    // 모든 조건 통과 시 경사로 놓았다고 표시
                    if (canLetRunway)
                    {
                        for (int i = 0; i < L; i++)
                        {
                            runway[y][nextX + i] = 1;
                            runwayList.push_back({y, nextX + i});
                        }
                        x += L - 1;
                    }
                    else
                    {
                        canPassLeft = false;
                        break;
                    }
                }
                else
                {
                    canPassLeft = false;
                    break;
                }
            }
            else if (nextHeight - height > 1)
            {
                canPassLeft = false;
                break;
            }
        }
        if (canPassLeft == false)
            continue;
        bool canPassRight = true;
        for (int x = N - 1; x > 0; x--)
        {
            int nextX = x - 1;
            int height = input[y][x];
            int nextHeight = input[y][nextX];

            // 높이가 다른 칸을 만나는지 체크
            // 높이가 다른 칸을 만나면 경사로를 놓을 수 있는지 체크
            // 1. 높이차가 1이어야 함
            // 2. 높이차가 1인 칸이 L 길이만큼 지속되어야 함
            // 3. L 길이의 경사로를 놓을 때 범위를 벗어나지 않아야 함.
            // 4. 경사로를 놓을 때 경사로가 있는지 체크해야 함.
            // 높이차 체크
            if (nextHeight - height == -1)
            {
                isFlatted = false;
                // 범위 체크
                if (x - L >= 0)
                {
                    bool canLetRunway = true;
                    for (int i = 0; i < L; i++)
                    {
                        // L길이의 높이차 체크
                        if (input[y][nextX - i] != nextHeight)
                        {
                            canLetRunway = false;
                            break;
                        }
                        // 경사로 체크
                        if (runway[y][nextX - i] != 0)
                        {
                            canLetRunway = false;
                            break;
                        }
                    }
                    // 모든 조건 통과 시 경사로 놓았다고 표시
                    if (canLetRunway)
                    {
                        for (int i = 0; i < L; i++)
                        {
                            runway[y][nextX - i] = 1;
                            runwayList.push_back({y, nextX - i});
                        }
                        x -= L - 1;
                    }
                    else
                    {
                        canPassRight = false;
                        break;
                    }
                }
                else
                {
                    canPassRight = false;
                    break;
                }
            }
            else if (nextHeight - height > 1)
            {
                canPassRight = false;
                break;
            }
        }
        // 평평함
        if (isFlatted)
        {
            res++;
            continue;
        }
        if (canPassRight && canPassLeft)
        {
            res++;
        }
        else
        {
        }
    }
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            runway[y][x] = 0;
        }
    }

    for (int x = 0; x < N; x++)
    {
        canPassLeft = true;
        isFlatted = true;
        for (int y = 0; y < N - 1; y++)
        {

            int nextY = y + 1;
            int height = input[y][x];
            int nextHeight = input[nextY][x];
            // 높이가 다른 칸을 만나는지 체크
            // 높이가 다른 칸을 만나면 경사로를 놓을 수 있는지 체크
            // 1. 높이차가 1이어야 함
            // 2. 높이차가 1인 칸이 L 길이만큼 지속되어야 함
            // 3. L 길이의 경사로를 놓을 때 범위를 벗어나지 않아야 함.
            // 4. 경사로를 놓을 때 경사로가 있는지 체크해야 함.
            // 높이차 체크
            if (nextHeight - height == -1)
            {
                isFlatted = false;
                // 범위 체크
                if (y + L < N)
                {
                    bool canLetRunway = true;
                    // 경사로 놓을 수 있는지 체크
                    for (int i = 0; i < L; i++)
                    {
                        // L길이의 높이차 체크
                        if (input[nextY + i][x] != nextHeight)
                        {
                            canLetRunway = false;
                            break;
                        }
                        // 경사로 체크
                        if (runway[nextY + i][x] != 0)
                        {
                            canLetRunway = false;
                            break;
                        }
                    }
                    // 모든 조건 통과 시 경사로 놓았다고 표시
                    if (canLetRunway)
                    {
                        for (int i = 0; i < L; i++)
                        {
                            runway[nextY + i][x] = 1;
                            runwayList.push_back({nextY + i, x});
                        }
                        y += L - 1;
                    }
                    else
                    {
                        canPassLeft = false;
                        break;
                    }
                }
                else
                {
                    canPassLeft = false;
                    break;
                }
            }
            else if (nextHeight - height > 1)
            {
                canPassLeft = false;
                break;
            }
        }
        bool canPassRight = true;
        for (int y = N - 1; y > 0; y--)
        {
            int nextY = y - 1;
            int height = input[y][x];
            int nextHeight = input[nextY][x];

            // 높이가 다른 칸을 만나는지 체크
            // 높이가 다른 칸을 만나면 경사로를 놓을 수 있는지 체크
            // 1. 높이차가 1이어야 함
            // 2. 높이차가 1인 칸이 L 길이만큼 지속되어야 함
            // 3. L 길이의 경사로를 놓을 때 범위를 벗어나지 않아야 함.
            // 4. 경사로를 놓을 때 경사로가 있는지 체크해야 함.
            // 높이차 체크
            if (nextHeight - height == -1)
            {
                isFlatted = false;
                // 범위 체크
                if (y - L >= 0)
                {
                    bool canLetRunway = true;
                    for (int i = 0; i < L; i++)
                    {
                        // L길이의 높이차 체크
                        if (input[nextY - i][x] != nextHeight)
                        {
                            canLetRunway = false;
                            break;
                        }
                        // 경사로 체크
                        if (runway[nextY - i][x] != 0)
                        {
                            canLetRunway = false;
                            break;
                        }
                    }
                    // 모든 조건 통과 시 경사로 놓았다고 표시
                    if (canLetRunway)
                    {
                        for (int i = 0; i < L; i++)
                        {
                            runwayList.push_back({nextY - i, x});
                            runway[nextY - i][x] = 1;
                        }
                        y -= L - 1;
                    }
                    else
                    {
                        canPassRight = false;
                        break;
                    }
                }
                else
                {
                    canPassRight = false;
                    break;
                }
            }
            else if (nextHeight - height > 1)
            {
                canPassRight = false;
                break;
            }
        }
        // 평평함
        if (isFlatted)
        {
            res++;
            continue;
        }
        if (canPassRight && canPassLeft)
        {
            res++;
        }
    }
    cout << res;
    return 0;
}
