#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<char> st;

    for (int idx = 0; idx < s.size(); ++idx)
    {
        if (!st.empty())
        {
            if (st.top() == '(' && s[idx] == ')')
            {
                st.pop();
                continue;
            }
        }
        st.push(s[idx]);
    }

    answer = st.empty() ? true : false;
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}
int main()
{
    string input = "()()";
    bool answer = solution(input);
}