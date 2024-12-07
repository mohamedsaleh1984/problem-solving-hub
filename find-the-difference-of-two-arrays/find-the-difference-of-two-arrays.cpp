#include <iostream>
#include <stack>
#include <vector>
#include <set>
using namespace std;

// https://leetcode.com/problems/find-the-difference-of-two-arrays/submissions/1472802239/?envType=study-plan-v2&envId=leetcode-75
// 27ms Beats 47.72%
// Date:12/07/2024

class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        vector<vector<int>> result;
        result.push_back({});
        result.push_back({});

        set<int> s1, s2;

        for (int i = 0; i < nums1.size(); i++)
        {
            s1.insert(nums1[i]);
        }

        for (int i = 0; i < nums2.size(); i++)
        {
            s2.insert(nums2[i]);
        }

        for (auto &e : s1)
        {
            if (s2.count(e) == 0)
            {
                result[0].push_back(e);
            }
        }

        for (auto &e : s2)
        {
            if (s1.count(e) == 0)
            {
                result[1].push_back(e);
            }
        }

        return result;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {2, 4, 6};

    cout << s.findDifference(v1, v2) << endl;

    return 0;
}
