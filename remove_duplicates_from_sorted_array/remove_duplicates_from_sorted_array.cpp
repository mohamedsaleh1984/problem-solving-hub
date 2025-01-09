#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;

// https://leetcode.com/problems/remove-duplicates-from-sorted-array
// 4ms Beats 11.81%
// 12/08/2024

class Solution {
public:
	    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        int left = 0, right = 0;
        
        while(right < nums.size()){
            if(nums[left] == nums[right]){
                right++;
            }
            else
            {
                k++;
                left++;
                nums[left] = nums[right];
                right++;
            }
        }
        
        
        return k;
    }
    int removeDuplicatesEx(vector<int>& nums) {
		nums.erase(unique(nums.begin(), nums.end()), nums.end());
		return nums.size();
    }
};

int main()
{
	vector<int> nums	= { 1,1,2 };
	vector<int> nums2	= { 0,1,2,2,3,0,4,2 };
	vector<int> nums3	= { 2,2,3 };

	Solution s = Solution();
	 
	cout << s.removeDuplicates(nums) << endl;
    cout << s.removeDuplicates(nums2 ) << endl;
    cout << s.removeDuplicates(nums2) << endl;

	return 0;
}
