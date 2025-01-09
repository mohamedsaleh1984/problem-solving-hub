#include "../common.h"

// https://leetcode.com/problems/maximum-subarray/
// 46ms Beats 98.76%

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        // saves a lot of time handling io to standard C streams
        ios_base::sync_with_stdio(0);

        int max_so_far = nums[0];
        int curr_max = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            curr_max = max(nums[i], curr_max + nums[i]);
            max_so_far = max(max_so_far, curr_max);
        }
        return max_so_far;
    }
};

int main(void)
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution s;

    cout << s.maxSubArray(nums) << endl;
    return 0;
}
