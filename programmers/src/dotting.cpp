#include <iostream>
#include <string>
#include <vector>
#include <cmath>


using namespace std;

int returnYVal(int x, int d, int k)
{
    return sqrt(pow(d, 2) - pow(x, 2));
}

vector<pair<int, int>> directions({{0, 1}, {1, 0}});

long long solution(int k, int d)
{
    long long answer = 0;
    for (int x = 0; x <= d; x = x + k)
    {
        int y = returnYVal(x, d, k);
        if (k == y)
        {
            answer += 2;
        }
        else if (k < y)
        {
            answer += y / k + 1;
        }
        else
        {
            answer += 1;
        }
    }

    return answer;
}
int main(int argc, char const *argv[])
{
    int k = 1;
    int d = 5;
    cout << solution(k, d);
    return 0;
}
