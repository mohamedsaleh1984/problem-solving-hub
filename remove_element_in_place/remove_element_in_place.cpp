#include <iostream>
#include <vector>
using namespace std;

//https://leetcode.com/problems/remove-element/
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		if (nums.size() == 0)
			return 0;

		int left = 0;
		int right = nums.size() - 1;

		while (left <= right) {
			while (nums[right] == val)
			{
				nums.pop_back();
				--right;
				if (right == -1)
					break;
			}

			if (right < 0)
				break;

			if (left >= nums.size() - 1)
				break;

			if (nums[left] == val && nums[right] != val) {
				nums[left] = nums[right];
				nums.pop_back();
				left++;
				right--;
			}
			while (nums[left] != val) {
				++left;
				if (left >= nums.size() - 1)
					break;
			}
		}
		return nums.size();
	}
};

int main()
{
	/*vector<int> nums = { 3,2,2,3 };
	int val = 3;*/

	Solution s;
	//cout << s.removeElement(nums, val) << endl;

	//cout << "array after modification..." << endl;
	//for (auto x : nums) {
	//    cout << x << " ";
	//}
	//
	//vector<int> nums2 = { 0,1,2,2,3,0,4,2 };
	//int val2 = 2;
	//cout << s.removeElement(nums2, val2) << endl;

	vector<int> nums3 = { 2,2,3 };
	int val3 = 2;
	cout << s.removeElement(nums3, val3) << endl;
	return 0;
}
