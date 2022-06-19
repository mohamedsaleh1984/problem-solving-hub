#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <stdexcept>
#include <queue>
using namespace std;

//https://leetcode.com/problems/01-matrix/
//Runtime: 94 ms, faster than 73.20% of C++ online submissions for 01 Matrix.


class Solution {
private:
	int COLS;
	int ROWS;
	const int MAX_DISTANCE = 10000;
	vector<vector<int>> mat;
public:
	void init(vector<vector<int>> mat)
	{
		this->mat = mat;
		this->ROWS = mat.size();
		this->COLS = mat[0].size();
	}

	vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
		init(mat);
		vector<vector<int>> result(mat.size());
		for (int i = 0; i < mat.size(); i++)
			result[i].resize(mat[i].size());

		for (int r = 0; r < mat.size(); r++)
			for (int c = 0; c < mat[r].size(); c++)
				result[r][c] = MAX_DISTANCE;


		for (int r = 0; r < result.size(); r++)
		{
			for (int c = 0; c < result[r].size(); c++)
			{
				if (mat[r][c] == 0) {
					result[r][c] = 0;
					continue;
				}
				if (r > 0)
					result[r][c] = min(result[r][c], result[r - 1][c] + 1);
				if (c > 0)
					result[r][c] = min(result[r][c], result[r][c - 1] + 1);

			}

		}

		for (int r = ROWS - 1; r >= 0; r--)
		{
			for (int c = COLS - 1; c >= 0; c--)
			{
				if (r != ROWS - 1)
					result[r][c] = min(result[r][c], result[r + 1][c] + 1);

				if (c != COLS - 1)
					result[r][c] = min(result[r][c], result[r][c + 1] + 1);
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
	//prointOut(mat);
	Solution s;
//	mat = s.updateMatrix(mat);
//	prointOut(mat);
//	
//	vector<vector<int>> mat2 = { {0,0,0},{0,1,0},{1,1,1} };
//	//prointOut(mat2);
//	mat2 = s.updateMatrix(mat2);
////	prointOut(mat2);
//
//	vector<vector<int>> mat3 = { {0,1,0},{1,0,1},{1,1,1},{1,1,1} };
//	mat3 = s.updateMatrix(mat3);

	vector<vector<int>> mat4 = { {0,1,0,1,1},{1,1,0,0,1},{0,0,0,1,0},{1,0,1,1,1},{1,0,0,0,1} };
	mat4 = s.updateMatrix(mat4);
	return 0;
}