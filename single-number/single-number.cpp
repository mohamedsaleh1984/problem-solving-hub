#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

// https://leetcode.com/problems/single-number/submissions/1449027291/?envType=study-plan-v2&envId=leetcode-75
/* 23ms Beats 6.27%*/
class Solution
{
public:
    int singleNumberBitXor(vector<int> &nums)
    {
        int result = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            result ^= nums[i];
        }
        return result;
    }

    int singleNumberPointer(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int num = 0;
        return num;
    }

    int singleNumberSets(vector<int> &nums)
    {
        set<int> sit;

        for (int i = 0; i < nums.size(); i++)
        {
            if (sit.count(nums[i]) == 0)
            {
                sit.insert(nums[i]);
            }
            else
            {
                sit.erase(nums[i]);
            }
        }
        int T = -1;
        if (!sit.empty())
        {
            for (std::set<int>::iterator it = sit.begin(); it != sit.end(); ++it)
            {
                T = *it;
            }
        }

        return T;
    }
};

int main(void)
{
    vector<int> vec = {4, 1, 2, 1, 2};
    Solution s;
    cout << s.singleNumberSets(vec) << endl;
    cout << s.singleNumberBitXor(vec) << endl;
    cout << s.singleNumberPointer(vec) << endl;
    return 0;
}
