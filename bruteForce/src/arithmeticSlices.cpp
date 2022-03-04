#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    static int numberOfArithmeticSlices(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int ret = 0;
        for (int i = 1; i < nums.size(); ++i)
        {
            int count = 1;
            int start = i;
            int diff = nums[start] - nums[start - 1];
            while (nums[start] - nums[start - 1] == diff)
            {
                start++;
                count++;
                if (start >= nums.size())
                    break;
            }
            if (count >= 3)
            {
                ret += count - 2;
            }
        }
        return ret;
    }
};
int main()
{
    vector<int> nums = {1, 3, 5, 7, 9};
    cout << Solution::numberOfArithmeticSlices(nums);
}