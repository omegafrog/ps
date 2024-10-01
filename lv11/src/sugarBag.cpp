#include <iostream>
using namespace std;

int sugarMem[1001][1668] = {
    0,
};

int main(int argc, char const *argv[])
{
    for (int i = 0; i <= 1000; i++)
    {
        for (int j = 0; j <= 1667; j++)
        {
            sugarMem[i][j] = 5 * i + 3 * j;
        }
    }
    bool flag = false;
    int N;
    cin >> N;
    int smallest = 987654321;
    for (int i = 0; i <= 1000; i++)
    {
        for (int j = 0; j <= 1667; j++)
        {
            if (N == sugarMem[i][j])
            {
                flag = true;
                if (smallest > i + j)
                {
                    smallest = i + j;
                }
            }
        }
    }
    if (flag == false)
    {
        cout << -1;
    }
    else
    {
        cout << smallest;
    }

    return 0;
}
