#include "../common.h"

//https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int left = 0;
		int right = 1;
		int size = nums.size();

		//right pointer has not reached to the end of the array
		while (right < nums.size() - 1) {
			//if the two adjacent items are not the same move left and right forward 
			while(nums[left] != nums[right]) {
				left++;
				right++;
			}

			//When the two adjacent items are equal
			//Count the occurance of dubplicated items
			int occuranceCounter = 0;
			int elemsCountToPop = 0;
			int val = nums[left];
			int rightPtr = right;
			//start moving the right pointer forward as long as there is duplication
			while (val == nums[rightPtr]) {
				++occuranceCounter;
				rightPtr++;
				if (rightPtr >= nums.size())
					break;
			}
			//find how many items are 
			int diff = rightPtr - left;
			//cout << "number of occuracnes of " << val << " is " << diff << endl;

			//number of occurance greater than 2 which our condition
			if (diff > 2) {
				//move the left pointer one step further so now the occurance are 2 in the array.
				//Start overwrite the elements from the left side with the elements
				//from the right side 
				left += 2;
				for (int i = left, j = rightPtr; j < size - 1; i++, j++) {
					nums[i] = nums[j];
				}
			}
			//number of extra items to remove from the rare of the list.
			if (diff > 2) {
				int pops = diff - 2;
				while (pops > 0) {
					nums.pop_back();
					--pops;
				}
				right = left + 1;
			}
			else {
				right++;
				left++;
			}
			//cout << "left " << left << " , right " << right << "\n";
		}
		return nums.size();
	}
};
int main()
{
	vector<int> nums = { 1,1,2 };
	vector<int> nums2 = { 0,0,0,1,1,1,1,2,2,3,3 };
	vector<int> nums3 = { 2,2,3 };

	Solution s = Solution();

	cout << s.removeDuplicates(nums) << endl;
	cout << s.removeDuplicates(nums2) << endl;
	cout << s.removeDuplicates(nums3) << endl;
	


	return 0;
}