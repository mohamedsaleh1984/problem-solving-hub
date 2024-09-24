#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <stdexcept>
#include <queue>
using namespace std;

//https://leetcode.com/problems/min-cost-climbing-stairs/
//TODO:FIX It
class Solution {
public:
	vector<int> steps;
	int minCostClimbingStairs(vector<int>& cost) {
		for (int i = 2; i < cost.size(); i++)
			cost[i] += min(cost[i - 1], cost[i - 2]);
		return min(cost[cost.size() - 1], cost[cost.size() - 2]);
	}

	int jump(vector<int>& nums) {
		//vector<vector<int>> dpArray(nums.size()+1);
		//for (int i = 0; i < dpArray.size(); i++) {
		//	dpArray[i].resize(dpArray.size()+1);
		//}
		//int j = 1;
		//for (int i = 1; i < dpArray.size(); i++) {
		//	
		///*		if (i - 1 == 0 && nums[i-1]< ) {

		//		}*/
		//		dpArray[i][j] = 1 + dpArray[i - 1][j - 1];
		//	
		//}

		//for (int i = 0; i < dpArray.size(); i++) {
		//	for (int j = 0; j < dpArray[i].size(); j++) {
		//		cout << dpArray[i][j] << " ";
		//	}
		//	cout << endl;
		//}

		return 0;
	}
};


int main()
{
	vector<int> vec = { 2,3,1,1,4 };
	Solution s;
	s.jump(vec);
    
}
 