#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void print_out(set<int> ss) {
	vector<int> yy(ss.begin(), ss.end());

	sort(yy.begin(), yy.end());
	for (auto s : yy)
		cout << s << " ";
	cout << endl;
}

bool checkValid(vector<vector<int>>& matrix) {
	int siz = matrix.size();

	for (int iRow = 0; iRow < matrix.size(); iRow++) {
		set<int> mySet;
		if (matrix[iRow].size() != siz)
			return false;

		for (int iCol = 0; iCol < matrix[iRow].size(); iCol++) {
			auto pos = mySet.find(matrix[iRow][iCol]);
			if (pos != mySet.end()) {
				return false;
			}
			else {
				if (matrix[iRow][iCol] >= 1 && matrix[iRow][iCol] <= matrix.size()) {
					mySet.insert(matrix[iRow][iCol]);
				}
				else
				{
					return false;
				}
			}
		}
	}
	return true;
}

int main()
{
	vector<vector<int>> matrix = {	{1,2,3,5,4},
									{1,2,3,5,4},
									{1,2,3,4,4},
									{1,2,4,5,4,},
									{13,1916,5,4}
								};


	cout << checkValid(matrix) << endl;
	return 0;
}
