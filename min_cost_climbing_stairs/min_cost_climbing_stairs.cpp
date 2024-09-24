#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//https://leetcode.com/problems/min-cost-climbing-stairs/
class Solution {
public:
	vector<int> steps;
	int minCostClimbingStairs(vector<int>& cost) {
		for (int i = 2; i< cost.size(); i++)
			cost[i] += min(cost[i - 1], cost[i - 2]);
		return min(cost[cost.size() - 1], cost[cost.size() - 2]);
	}
};

int main()
{
	Solution s;
	vector<int> cost = { 10, 15, 20 };
	cout << s.minCostClimbingStairs(cost) << endl;
	vector<int> cost2 = { 1,100,1,1,1,100,1,1,100,1 };
	cout << s.minCostClimbingStairs(cost2) << endl;

	return 0;
}
