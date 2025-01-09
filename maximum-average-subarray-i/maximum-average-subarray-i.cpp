#include "../common.h"

// https://leetcode.com/problems/maximum-average-subarray-i/?envType=study-plan-v2&envId=leetcode-75
// 12/15/2024
// 0 ms Beats 100.00%
class Solution
{
private:
    double maxAvg = INT_MIN;
    double curSum = 0;
    double curAvg = 0;
    int k;

public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        this->k = k;
        int len = nums.size();

        if (nums.size() == 0)
            return 0;

        if (nums.size() == 1)
            return nums[0];

        int left = 0;
        int right = k;
        // compute the sum for first Window
        for (int i = left; i < right; i++)
            curSum += nums[i];

        setMaxAvg();

        while (right < len)
        {
            // remove first number
            curSum -= nums[left];
            left++;
            curSum += nums[right];

            setMaxAvg();

            right++;
        }

        return maxAvg;
    }
    void setMaxAvg()
    {
        // compute the avg for first Window
        curAvg = curSum / k;

        if (curAvg > maxAvg)
            maxAvg = curAvg;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    vector<int> vec = {1, 12, -5, -6, 50, 3};
    vector<int> vec2 = {0, 1, 1, 3, 3};

    cout << s.findMaxAverage(vec2, 4) << endl;

    return 0;
}
