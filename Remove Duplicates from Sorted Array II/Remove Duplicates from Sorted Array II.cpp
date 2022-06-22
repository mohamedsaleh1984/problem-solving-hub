#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <unordered_map>
using namespace std;

//https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int left = 0;
		int rigt = 1;
		int size = nums.size();

		while (left < right) {
			if (nums[left] != nums[right]) {

			}
		}
		

	}
};
int main()
{
	vector<int> nums = { 1,1,2 };
	vector<int> nums2 = { 0,1,2,2,3,0,4,2 };
	vector<int> nums3 = { 2,2,3 };

	Solution s = Solution();

	cout << s.removeDuplicates(nums) << endl;
	cout << s.removeDuplicates(nums2) << endl;
	cout << s.removeDuplicates(nums2) << endl;

	return 0;
}
