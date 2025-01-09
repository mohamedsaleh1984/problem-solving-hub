// Codility_01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "../common.h"

int solution(vector<int> A)
{
	/*HashSet<int> h = new HashSet<int>();

	foreach(int val in A)
		if (val > 0)
			h.Add(val);

	int minpostive = 1;

	for each (int val in h)
	{
		if (val == minpostive)
			do
			{
				minpostive++;
			} while (h.Contains(minpostive));
	} */

	return 0;
}
int main()
{
	vector<int> A{ 1, 3, 6, 4, 1, 2 };
	vector<int> B{ 1, 2, 3 };
	vector<int> C{ -1, -3 };
	vector<int> D{ -1 };
	//cout << solution(D) << endl;
	cout << solution(B) << endl;
	cout << solution(C) << endl;
	return 0;
}
