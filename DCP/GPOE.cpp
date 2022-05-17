#include "GPOE.h"

vector<int> GPOE::solve(vector<int> v) {
	vector<int> res; res.resize(v.size());
	int totalProduct = 1;
	
	for (int i = 0; i < v.capacity(); ++i)
		totalProduct *= v[i];
	
	for (int i = 0; i < v.size(); ++i)
		res[i] = totalProduct / v[i];

	return res;
}

vector<int> GPOE::solve2(vector<int> v) {
	vector<int> res; res.resize(v.size());
	vector< vector<int>> T;

	for (size_t i = 0; i < v.size(); i++)
	{
		vector<int> row;
		int p;
		if (i == 0)
			p = 1;
		for (int c = 1; c < v.size(); c++)
		{
			p *= v[c];
			row.push_back(p);
		}
		T.push_back(row);
	}

	


	return res;
}