#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int cnt = 1;
    int whitespace = n - 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < whitespace; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < cnt; j++)
        {
            cout << "*";
        }
        cout << "\n";
        cnt += 2;
        whitespace -= 1;
    }
    whitespace += 1;
    cnt -= 2;
    for (int i = 0; i < n - 1; i++)
    {
        whitespace += 1;
        cnt -= 2;
        for (int j = 0; j < whitespace; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < cnt; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }

    return 0;
}
