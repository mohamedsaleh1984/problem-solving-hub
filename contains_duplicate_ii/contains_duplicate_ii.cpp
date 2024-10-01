#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
https://leetcode.com/problems/contains-duplicate-ii/
133ms Beats31.60%
*/
bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        if (mp.count(nums[i]) && abs(mp[nums[i]] - i) <= k)
            return true;
        mp[nums[i]] = i;
    }
    return false;
}
int main()
{
    vector<int> nums = {1, 2, 3, 1};
    int k = 3;
    cout << containsNearbyDuplicate(nums, k) << endl;
}
