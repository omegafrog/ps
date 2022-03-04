#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    static double champagneTower(int poured, int query_row, int query_glass)
    {
        vector<vector<double>> glasses;
        for (int i = 0; i <= query_row + 1; ++i)
        {
            vector<double> glass(i + 1, 0);
            glasses.push_back(glass);
        }
        glasses[0][0] = poured;
        for (int row = 0; row <= query_row; ++row)
        {
            for (int column = 0; column < glasses[row].size(); ++column)
            {
                if (glasses[row][column] > 1)
                {
                    double overflowed = glasses[row][column] - 1;
                    glasses[row + 1][column] += overflowed / 2;
                    glasses[row + 1][column + 1] += overflowed / 2;
                    glasses[row][column] = 1;
                }
            }
        }
        return glasses[query_row][query_glass];
    }
};
int main()
{
    int poured = 100000009, query_row = 33, query_glass = 17;
    Solution::champagneTower(poured, query_row, query_glass);
}