#include <iostream>
using namespace std;

int **arr1;
int **arr2;

int main(int argc, char const *argv[])
{
    int N, M;
    cin >> N >> M;

    arr1 = (int **)malloc(sizeof(int *) * N);
    for (int i = 0; i < N; i++)
    {
        arr1[i] = (int *)malloc(sizeof(int) * M);
    }

    arr2 = (int **)malloc(sizeof(int *) * N);
    for (int i = 0; i < N; i++)
    {
        arr2[i] = (int *)malloc(sizeof(int) * M);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr1[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr2[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << arr1[i][j] + arr2[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
