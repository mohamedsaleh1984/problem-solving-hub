#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <stdexcept>
#include <queue>
using namespace std;

//https://leetcode.com/problems/01-matrix/
//TODO: Write the algo


class Solution {
private:
	vector<vector<bool>> visited;
	vector<vector<int>> mat;
	int COLS;
	int ROWS;
public:
	void init(vector<vector<int>> mat)
	{
		this->mat = mat;
		this->ROWS = mat.size();
		this->COLS = mat[0].size();
	}

	vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
		init(mat);
		vector<vector<int>> result = mat;
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++) {
				int row = i;
				int col = j;

				if (mat[row][col] == 1)
				{
					if (col + 1 < COLS && mat[row][col + 1] == 0)
						result[row][col] = 1;
					else if (col - 1 >= 0 && mat[row][col - 1] == 0)
						result[row][col] = 1;
					else if (row - 1 >= 0 && mat[row - 1][col] == 0)
						result[row][col] = 1;
					else if (row + 1 < ROWS && mat[row + 1][col] == 0)
						result[row][col] = 1;
					else if (col + 1 < COLS && mat[row][col + 1] == 1)
						result[row][col] = result[row][col + 1] + 1;
					else if (col - 1 >= 0 && mat[row][col - 1] == 1)
						result[row][col] = result[row][col - 1] + 1;
					else if (row - 1 >= 0 && mat[row - 1][col] == 1)
						result[row][col] = result[row - 1][col] + 1;
					else if (row + 1 < ROWS && mat[row + 1][col] == 1)
						result[row][col] = result[row + 1][col] + 1;
				}
			}
		}
		return result;
	}
};


void prointOut(vector<vector<int>>  vec)
{
	for (auto row : vec){
		for (auto col : row) {
			cout << col << " ";
		}
		cout << "\n";
	}
	cout << endl;
}

int main()
{
	vector<vector<int>> mat = { {0,0,0},{0,1,0},{0,0,0} };
	prointOut(mat);
	Solution s;
	mat = s.updateMatrix(mat);
	prointOut(mat);
	vector<vector<int>> mat2 = { {0,0,0},{0,1,0},{1,1,1} };
	prointOut(mat2);
	mat2 = s.updateMatrix(mat2);
	prointOut(mat2);

	return 0;
}