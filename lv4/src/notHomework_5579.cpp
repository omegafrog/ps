#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> v(30, 0);
    for (int i = 0; i < 28; i++)
    {
        int tmp;
        cin >> tmp;
        v[tmp - 1] = 1;
    }
    int first = -1, second = -1;
    for (int i = 0; i < 30; ++i)
    {
        if (v[i] == 0 && first == -1)
        {
            first = i;
        }
        else if (v[i] == 0)
        {
            second = i;
        }
    }
    if (first > second)
    {
        int tmp = first;
        first = second;
        second = tmp;
    }
    cout << first + 1 << "\n"
         << second + 1;

    return 0;
}
