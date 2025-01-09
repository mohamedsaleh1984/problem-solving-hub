#include "../common.h"

/*
 https://leetcode.com/problems/top-k-frequent-elements
*/
vector<int> topKFrequent(vector<int> &nums, int k)
{
    vector<int> result = {};
    map<int, int> zmap;
    for (int i = 0; i < nums.size(); i++)
    {
        zmap[nums[i]]++;
    }
    priority_queue<pair<int, int>> topFreq;
    map<int, int>::iterator itr = zmap.begin();
    while (itr != zmap.end())
    {
        topFreq.push(make_pair(itr->second, itr->first));
        itr++;
    }
    while (k != 0)
    {
        pair<int, int> t = topFreq.top();
        topFreq.pop();
        result.push_back(t.second);
        k--;
    }

    return result;
}

int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> xxx = topKFrequent(nums, k);
}
