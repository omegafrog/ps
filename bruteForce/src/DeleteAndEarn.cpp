#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        return getMax(nums);
    }
    int getMax(vector<int> &nums)
    {
        int ret = 0;
        if (nums.size() == 0)
        {
            return ret;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            vector<int> original(nums.begin(), nums.end());
            int selected = nums[i];
            int countSelected = 1;
            nums.erase(nums.begin() + i);
            auto it = find(nums.begin(), nums.end(), selected);
            while (it != nums.end())
            {
                nums.erase(it);
                it = find(nums.begin(), nums.end(), selected);
                countSelected++;
            }
            it = find(nums.begin(), nums.end(), selected + 1);
            while (it != nums.end())
            {
                nums.erase(it);
                it = find(nums.begin(), nums.end(), selected + 1);
            }
            it = find(nums.begin(), nums.end(), selected - 1);
            while (it != nums.end())
            {
                nums.erase(it);
                it = find(nums.begin(), nums.end(), selected - 1);
            }

            ret = max(ret, selected * countSelected + getMax(nums));
            nums = original;
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {7, 5, 4, 9, 5, 1, 1, 10, 4, 8, 6, 8, 3, 10, 8, 6, 7, 6, 4, 1, 5, 9, 6, 6, 6, 5, 3, 2, 10, 3, 5, 6, 9, 7, 3, 6, 2, 4, 10, 8, 4, 8, 6, 1, 3, 2, 9, 8, 2, 6};
    cout << s.deleteAndEarn(nums);
    return 0;
}
