#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <set>
using namespace std;

template <class T, class U>
bool sortByThirdItemAscending(const tuple<T, T, U> &a,
							  const tuple<T, T, U> &b)
{
	return (get<2>(a) > get<2>(b));
}
bool sortByThirdItemAscendingEx(const tuple<int, int, float> &a,
								const tuple<int, int, float> &b)
{
	return (get<2>(a) > get<2>(b));
}

template <class T, class U>
void dumpVector(vector<tuple<T, T, U>> &vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		tuple<T, T, U> item = vec[i];
		cout << "{" << get<0>(item) << "," << get<1>(item) << "," << get<2>(item) << "}\n";
	}
}

float MaxValue(int bagWeight, vector<int> values, vector<int> weights)
{
	vector<tuple<int, int, float>> givens;
	for (int i = 0; i < values.size(); i++)
	{
		givens.push_back({values[i], weights[i], (float)values[i] / (float)weights[i]});
	}
	sort(givens.begin(), givens.end(), sortByThirdItemAscendingEx);
	// dumpVector(givens);

	float value = 0;
	int usedWeight = 0;
	int fff = bagWeight;
	for (int i = 0; i < givens.size() && bagWeight > 0; i++)
	{
		tuple<int, int, float> curItem = givens[i];
		int itemWeight = get<1>(curItem);
		float itemWorthPerItem = get<2>(curItem);

		if (itemWeight + usedWeight < bagWeight)
		{
			usedWeight += itemWeight;
			value += (itemWeight * itemWorthPerItem);
			bagWeight -= usedWeight;
		}
		else
		{
			int remainingWeight = fff - usedWeight;
			value += (remainingWeight * itemWorthPerItem);
			usedWeight += remainingWeight;
			bagWeight = 0;
		}
	}

	return value;
}

int main()
{
	vector<int> weights{10, 20, 30};
	vector<int> values{60, 100, 120};
	int bagWeight = 50;
	cout << MaxValue(bagWeight, values, weights);

	/*
	vector<int> items{20,30,10};
	vector<int> values{ 100,120,60 };
	//		weight, value, divition
	vector<tuple<float, float, float>> givens;
	givens.push_back({ 6,6,0 });
	givens.push_back({ 10,2,0 });
	givens.push_back({ 3,1,0 });
	givens.push_back({ 5,8,0 });
	givens.push_back({ 1,3,0 });
	givens.push_back({ 3,5,0 });

	for (int i = 0; i < givens.size(); i++) {
		tuple<float, float, float> item = givens[i];
		get<2>(item) = (get<1>(item) / get<0>(item));
		givens[i] = item;
	}
	//dumpVector(givens);
	int weight = 10;
	sort(givens.begin(), givens.end(), sortByThirdValue);
	//cout << "after \n";
	//dumpVector(givens);
	*/
	return 0;
}
