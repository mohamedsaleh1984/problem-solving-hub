#include "../common.h"
//https://leetcode.com/problems/contains-duplicate/
//98ms Beats42.48%

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> hashset;
        for (int key : nums)
        {
            if (hashset.count(key) > 0)
                return true;
            
            hashset.insert(key);
        }
        return false;
    }
};


int main(void){
    Solution s;
    vector<int> vec = {1,2,3,1};

    cout <<  s.containsDuplicate(vec) << endl;


    return 0;
}
