#include "../common.h"
 
//https://leetcode.com/problems/house-robber/
class Solution {
public:
    int rob(vector<int>& nums) {
        int r1=0,r2 = 0;
        for (int i = 0; i < nums.size();i++ ) {
            int temp = max(nums[i] + r1, r2);
            r1 = r2;
            r2 = temp;
        }
        return r2;
    }

    int rob2(vector<int>& nums) {
        return helper(nums, nums.size());
    }
    int helper(vector<int>& nums, int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);

        vector<int> memo(n);
        memo[0] = nums[0];
        memo[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++)
            memo[i] = max(nums[i] + memo[i - 2], memo[i - 1]);

        return memo[n - 1];
    }
};


int main()
{
    Solution s = Solution();
    vector<int> house = { 1,2,3,1};
    cout << s.rob(house) << endl;
    return 0;
}
