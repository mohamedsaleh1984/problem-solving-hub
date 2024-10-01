#include <iostream>
#include <vector>
#include <hashtable.h>
using namespace std;

// https://leetcode.com/problems/search-in-rotated-sorted-array
// 0ms Beats100.00%

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        if(nums.size() == 0)
            return -1;
        if(nums.size() == 1 && nums[0] != target)
            return -1;
            
        
        int index = findMinIndex(nums);
        // sorted array
        if (index == -1)
        {
            return bs(nums, 0, nums.size(), target);
        }

        int leftHalf = bs(nums, 0, index - 1, target);
        int rightHalf = bs(nums, index, nums.size(), target);
        if (leftHalf == -1 && rightHalf == -1)
            return -1;
        return max(leftHalf, rightHalf);
    }

private:
    int bs(vector<int> &nums, int l, int r, int target)
    {
        if (l > r)
            return -1;

        if( l == r && l >= nums.size())
            return -1;

        int mid = (r + l) / 2;

        if (nums[mid] == target)
            return mid;

        if (target > nums[mid])
            return bs(nums, mid + 1, r, target);

        return bs(nums, l, mid - 1, target);
    }

    int findMinIndex(vector<int> &nums)
    {
        std::ios::sync_with_stdio(false);
        for (int i = 0, j = i + 1; j < nums.size(); ++i, ++j)
        {
            if (nums[j] < nums[i])
                return j;
        }
        return -1;
    }
};

int main(void)
{
    vector<int> vec = {1, 3};
    Solution s;
    cout << s.search(vec, 4) << endl;
}