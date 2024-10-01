#include <iostream>
#include <vector>
#include <map>
using namespace std;

//https://leetcode.com/problems/two-sum/
//6ms Beats 88.40%

vector<int> twoSumUsingHashMap(vector<int>& nums, int target) {
	vector<int> vec;
	map<int, int> mp;

	for (int i = 0; i < nums.size(); i++) {

		int rem = target - nums[i];

		if (mp.count(rem))
		{
			vec.push_back(mp[rem]);
			vec.push_back(i);
			break;
		}
		else
		{
			mp[nums[i]] = i;
		}
	}
	return vec;
}

vector<int> twoSumUsingLoops(vector<int>& nums, int target) {
	vector<int> vec;
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = i + 1; j < nums.size(); j++)
		{
			if (nums[i] + nums[j] == target)
			{
				vec.push_back(i);
				vec.push_back(j);
				return vec;
			}
		}
	}
	return vec;
}


int main()
{
	vector<int> nums = { -3,4,3,90 };
	int target = 0;
	vector<int> result = twoSumUsingHashMap(nums, target);
	for (auto a : result)
		cout << a << endl;
	return 0;
}