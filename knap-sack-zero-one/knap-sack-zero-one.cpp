#include "../common.h"

int KnapsackAux(vector<int> profits, vector<int> weights, int capacity, int currIndex);

int Knapsack(vector<int> profits, vector<int> weights, int capacity) {
	return KnapsackAux(profits,weights,capacity, 0);
}

int KnapsackAux(vector<int> profits, vector<int> weights, int capacity, int currIndex) {
	if (capacity <= 0 || currIndex < 0 || currIndex >= profits.size())
		return 0;
	int prof1 = 0;
	if (weights[currIndex] <= capacity)
		prof1 = profits[currIndex] + KnapsackAux(profits, weights, capacity - weights[currIndex], currIndex + 1);
	int prof2 = KnapsackAux(profits, weights, capacity, currIndex + 1);
	return max(prof1, prof2);
}


int main()
{
	vector<int> profits = {};
	vector<int> weights = {};
	int capacity = 0;

	cout << Knapsack(profits, weights, 10) << endl;
	return 0;
}
