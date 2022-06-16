#include <iostream>
#include <vector>
using namespace std;

//https://leetcode.com/problems/min-cost-climbing-stairs/
//TODO: Fix it
class Solution {
public:
    vector<int> steps;
    int minCostClimbingStairs(vector<int>& cost) {
        int total_cost = 0;

        if (cost.size() == 2) {
            total_cost = min(cost[0], cost[1]);
            return total_cost;
        }

        if (cost.size() == 3) {
            int first = min(cost[0] + cost[1], cost[0] + cost[2]);
            total_cost = min(first, cost[1]);
            return total_cost;
        }

        for (int i = 0; i < cost.size()-2; i++) {
            total_cost +=
        
        }
        return total_cost;
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
