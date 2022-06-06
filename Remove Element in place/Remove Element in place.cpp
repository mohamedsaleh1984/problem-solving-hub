#include <iostream>
#include <vector>
using namespace std;

//https://leetcode.com/problems/remove-element/
//TODO:Continue the solution hint pop the right after swap and return the size of the array.
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0)
            return 0;
        int left = 0;
        int right = nums.size()-1;

        while (left < right) {

            while (nums[left] != val)
                left++;

            if (nums[left] == val && nums[right] != val) {
                nums[left] = nums[right];
                nums[right] = val;
                left++;
                right--;
                nums.pop_back();
            }
            else
            {
                right--;
                nums.pop_back();
            }
        }
        return nums.size();
    }
};

int main()
{
    vector<int> nums = { 3,2,2,3 };
    int val = 3;
    
    Solution s;
    cout << s.removeElement(nums, val) << endl;

    cout << "array after modification..." << endl;
    for (auto x : nums) {
        cout << x << " ";
    }
    

    return 0;
}
