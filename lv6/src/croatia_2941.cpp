#include <iostream>
using namespace std;

string croatia[] = {
    "c=",
    "c-",
    "d-",
    "lj",
    "nj",
    "s=",
    "z="};

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    int cnt = 0;
    int i = 0;
    for (i; i < s.size() - 1; i++)
    {
        string tmp = s.substr(i, 2);
        if (tmp.compare("dz") == 0)
        {
            if (i + 2 < s.size() && s[i + 2] == '=')
            {
                cnt++;
                i += 2;
                continue;
            }
        }
        bool flag = false;
        for (int j = 0; j < 7; j++)
        {
            if (tmp.compare(croatia[j]) == 0)
            {
                cnt++;
                i += 1;
                flag = true;
            }
            if (flag)
                break;
        }
        if (flag)
            continue;
        cnt++;
    }
    if (i == s.size() - 1)
        cnt++;
    cout << cnt;

    return 0;
}
