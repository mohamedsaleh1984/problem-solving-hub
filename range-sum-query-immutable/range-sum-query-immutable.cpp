#include "../common.h"

// https://leetcode.com/problems/range-sum-query-immutable/
// 3ms Beats 50.48%
// 12/04/2024
class NumArray
{
public:
    vector<int> prefixSum;
    vector<int> vals;

    NumArray(vector<int> &nums)
    {
        prefixSum.push_back(0);
        for(auto x: nums)
            prefixSum.push_back(x + prefixSum.back());
        
        for(auto t: prefixSum)
            cout << t <<" " ;
        cout << endl; 

    }

    int sumRange(int left, int right)
    {
        return prefixSum[right-1]- prefixSum[left];
    }

};
 

int main(int argc, char **argv)
{
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray cls(nums);


    cout << "***************" << endl;
    cout << cls.sumRange(0, 2) << endl;
    cout << cls.sumRange(2, 5) << endl;
    cout << cls.sumRange(0, 5) << endl;
    cout << cls.sumRange(0, 2) << endl;

    return 0;
}