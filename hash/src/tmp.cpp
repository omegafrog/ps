
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> diffs;
    vector<int> ret;
    for (int i = 0; i < nums.size(); ++i)
    {
        int diff = target - nums[i] + 1000000000;
        diffs[diff] = i;
    }
    for (int i = 0; i < nums.size(); ++i)
    {
        int diff = nums[i] + 1000000000;
        if (diffs[diff] == i)
            continue;
        if (diffs.count(diff) > 0)
        {
            ret.push_back(i);
            ret.push_back(diffs[diff]);
            break;
        }
    }
    return ret;
}
int main()
{
    vector<int> a = {-1, -2, -3, -4, -5};
    int target = -8;
    vector<int> ret = twoSum(a, target);
    for (auto num : ret)
    {
        cout << num;
    }
}
