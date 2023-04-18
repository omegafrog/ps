#include <iostream>
#include <vector>
#define pair pair<int, int>
using namespace std;

int solution(int n, int k, vector<pair> &items)
{
    int **mem = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
    {
        mem[i] = (int *)malloc(sizeof(int) * k);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            mem[i][j] = -1;
        }
    }

    mem[0][0] = 0;
    int biggest = -1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (mem[i - 1][j] != -1)
                mem[i][j] = mem[i - 1][j];
            if (items[i - 1].first <= j)
            {
                if (mem[i - 1][j - items[i - 1].first] >= 0)
                {
                    mem[i][j] = max(mem[i][j], mem[i - 1][j - items[i - 1].first] + items[i - 1].second);
                    biggest = max(biggest, mem[i][j]);
                }
            }
        }
    }
    return biggest;
}

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;

    vector<pair> items;
    for (int i = 0; i < n; i++)
    {

        int w, v;
        cin >> w >> v;
        items.push_back({w, v});
    }

    int res = solution(n + 1, k + 1, items);
    if (res == -1)
    {
        cout << 0;
    }
    else
    {
        cout << res;
    }

    return 0;
}
