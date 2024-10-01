#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        string s;
        cin >> s;
        cout << s[0] << s[s.size() - 1] << "\n";
    }

    return 0;
}
