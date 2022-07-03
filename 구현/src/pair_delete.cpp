#include <iostream>
#include <string>
using namespace std;

int solution(string s)
{
    int answer = -1;
    int checked = 1;
    char a, b;
    string after = s;
    while (checked != 0)
    {
        for (int i = 1; i < after.size(); ++i)
        {
            checked = 0;
            a = after[i - 1];
            b = after[i];
            if (a == b)
            {
                after = after.substr(0, i - 1) + after.substr(i + 1, after.size() - (i + 1));
                checked = 1;
                break;
            }
        }
    }
    if (after.size() == 0)
    {
        answer = 1;
    }
    else
    {
        answer = 0;
    }

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.

    return answer;
}
int main()
{
    string input = "baabaa";
    int output = solution(input);
}