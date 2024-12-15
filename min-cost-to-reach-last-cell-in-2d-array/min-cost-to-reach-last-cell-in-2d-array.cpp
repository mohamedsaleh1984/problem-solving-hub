#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int MinCostAux(vector<vector<int>> matrix, int row, int col );

int MinCost(vector<vector<int>> matrix) {
	return MinCostAux(matrix,matrix[0].size()-1, matrix[0].size() - 1);
}
/*
	from down,right corner to UP.
	We have to do it this way because 
*/
int MinCostAux(vector<vector<int>> matrix, int row, int col ) {
	if (row == -1 || col == -1)
		return INT_MAX;
	if (row == 0 && col == 0)
		return matrix[row][col];

	int rightStep = MinCostAux(matrix, row, col - 1);
	int downStep = MinCostAux(matrix, row - 1, col);
	return matrix[row][col] + min(rightStep, downStep);
}

int main()
{
	vector<vector<int>> matrix = {
		{ 4, 7, 8, 6, 4 },
		{ 6, 7, 3, 9, 2 },
		{ 3, 8, 1, 2, 4 },
		{ 7, 1, 7, 3, 7 },
		{ 2, 9, 8, 9, 3 }
	};

	cout << MinCost(matrix);

	return 0;
}
