#include <iostream>
#include <stack>
using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;

    stack<char> stack;
    int mid;
    if (s.length() % 2 == 1)
    {
        mid = s.length() / 2;
        s.erase(s.begin() + mid);
    }
    for (int i = 0; i < s.length(); ++i)
    {
        if (!stack.empty())
        {
            char cur = stack.top();
            if (cur == s[i])
            {
                stack.pop();
                continue;
            }
        }
        stack.push(s[i]);
    }

    if (stack.empty())
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    return 0;
}
