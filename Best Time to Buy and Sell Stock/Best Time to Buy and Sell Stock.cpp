#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//
class Solution {
public:
	int maxProfit(vector<int>& prices) {
        int sell = 0;
        int buy = INT_MAX;

        for (int price : prices) {
            if (price < buy)
                buy = price;
            else
                sell = max(sell, price - buy);
        }
        return sell;
	}
};

int main()
{
	vector<int> prices = { 7,1,5,3,6,4 };
	Solution s;
	cout << s.maxProfit(prices);

	return 0;
}
