// Triple sum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;

/*
Problem:
https://www.hackerrank.com/challenges/triple-sum/problem
*/

long triplets(vector<int> a, vector<int> b, vector<int> c) {
	set<pair<int, int>> mm;
	for (int p = 0; p < a.size(); ++p)
		for (int q = 0; q < b.size(); ++q)
			if (a[p] <= b[q]) {
				mm.insert(pair<int, int>(a[p], b[q]));
			}

	long T = 0;
	set<pair<int, int>>::iterator itr;
	itr = mm.begin();

	set<int> cSet;
	for (int j = 0; j < c.size(); j++)
		cSet.insert(c[j]);


	set<int>::iterator itr2;
	for (; itr != mm.end(); ++itr)
	{
		pair<int, int> p = *itr;
		itr2 = cSet.begin();
		for (; itr2 != cSet.end(); ++itr2)
		{
			if (*itr2 <= p.second)
				T++;
		}
	}
	return T;
}


int main()
{
	vector<int> a = { 3, 2 ,3 };
	vector<int> b = {1,3,5};
	vector<int> c = { 2,3 };

	cout << triplets(a, b, c) << endl;

	return 0;
}

