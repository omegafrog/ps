#include <iostream>

#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
    vector<int> answer;
    int **board = (int **)malloc(sizeof(int *) * rows);
    for (int y = 0; y < rows; ++y)
    {
        board[y] = (int *)malloc(sizeof(int) * columns);
    }
    int a = 1;
    for (int y = 0; y < rows; ++y)
    {
        for (int x = 0; x < columns; ++x)
        {
            board[y][x] = a++;
        }
    }
    for (vector<int> query : queries)
    {
        int startY = query[0] - 1;
        int startX = query[1] - 1;
        int endY = query[2] - 1;
        int endX = query[3] - 1;
        deque<int> q;
        int curX = startX;
        int curY = startY;
        for (curX; curX < endX; ++curX)
        {
            q.push_back(board[curY][curX]);
        }
        for (curY; curY < endY; ++curY)
        {
            q.push_back(board[curY][curX]);
        }
        for (curX; curX > startX; --curX)
        {
            q.push_back(board[curY][curX]);
        }
        for (curY; curY > startY; --curY)
        {
            q.push_back(board[curY][curX]);
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        queue<int> q2(q);
        for (int i = 0; i < q.size(); ++i)
        {
            pq.push(q2.front());
            q2.pop();
        }
        answer.push_back(pq.top());
        int tmp = q.back();
        q.pop_back();
        q.push_front(tmp);

        for (curX; curX < endX; ++curX)
        {
            board[curY][curX] = q.front();
            q.pop_front();
        }
        for (curY; curY < endY; ++curY)
        {
            board[curY][curX] = q.front();
            q.pop_front();
        }
        for (curX; curX > startX; --curX)
        {
            board[curY][curX] = q.front();
            q.pop_front();
        }
        for (curY; curY > startY; --curY)
        {
            board[curY][curX] = q.front();
            q.pop_front();
        }
    }
    return answer;
}

int main(int argc, char const *argv[])
{
    // vector<vector<int>> v({{2, 2, 5, 4}, {
    //                                          3,
    //                                          3,
    //                                          6,
    //                                          6,
    //                                      },
    //                        {5, 1, 6, 3}});
    vector<vector<int>> v({{1,1,2,2}});
    solution(2,2, v);
    return 0;
}
