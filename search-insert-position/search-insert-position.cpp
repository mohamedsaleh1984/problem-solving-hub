#include "../common.h"

//https://leetcode.com/problems/search-insert-position/
int searchInsert(vector<int>& nums, int target) {
	long int low = 0;
	long int high = nums.size()-1;
	long int mid =-1, result=-1;

	while (low < high) {
		mid = (low + high) / 2;
	
		if (target == nums[mid])
			return mid;
	
		if (target > nums[mid])
		{
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	 
	return low;
}

int main()
{
	vector<int> nums = { 1, 3, 5, 6 };
	//cout << searchInsert(nums, 1) << endl;
	//cout << searchInsert(nums,7) << endl;
	cout << searchInsert(nums, 2) << endl;
	cout << searchInsert(nums, 10) << endl;

	return 0;
}
