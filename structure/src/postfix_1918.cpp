#include <iostream>
#include <stack>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<char> res;
    stack<char> post;
    for (auto it = s.begin(); it != s.end(); ++it)
    {

        switch (*it)
        {
        case '+':
        case '-':
            while (!post.empty() && !(post.top() == '('))
            {
                res.push_back(post.top());
                post.pop();
            }

            post.push(*it);
            break;
        case '*':
        case '/':
            while (!post.empty() && !(post.top() == '+' || post.top() == '-' || post.top() == '('))
            {
                res.push_back(post.top());
                post.pop();
            }
            post.push(*it);
            break;
        case '(':
            post.push(*it);
            break;
        case ')':
            while (!(post.top() == '('))
            {
                res.push_back(post.top());
                post.pop();
            }
            post.pop();
            break;
        default:
            res.push_back(*it);
            break;
        }
    }
    while (!(post.empty()))
    {
        res.push_back(post.top());
        post.pop();
    }
    for (auto it = res.begin(); it != res.end(); ++it)
    {

        cout << *it;
    }
}