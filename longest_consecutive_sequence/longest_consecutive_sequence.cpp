#include "../common.h"
// https://leetcode.com/problems/longest-consecutive-sequence/

int longestConsecutive(vector<int> &nums)
{
	if (nums.size() == 0 || nums.size() == 1)
		return nums.size();

	int GlobalMax = 0;
	set<int> mySet(nums.begin(), nums.end());
	vector<int> nums2(mySet.begin(), mySet.end());
	if (nums2.size() == 1)
		return 1;

	sort(nums2.begin(), nums2.end());
	for (size_t i = 0; i < nums2.size() - 1;)
	{
		int localMax = 1;
		while (nums2[i + 1] == nums2[i] + 1)
		{
			localMax++;
			i++;
			if (i + 1 >= nums2.size())
				break;
		}
		GlobalMax = max(GlobalMax, localMax);
		i++;
	}
	return GlobalMax;
}

int main()
{
	vector<int> nums = {10, 1, 2, 9, 3, 4, 5, 11, 11, 12, 13, 14, 14, 14, 15, 16, 16, 16};
	cout << longestConsecutive(nums) << endl;

	return 0;
}