// SpiralMatrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> matrix) {
	vector<int> vec = {};
	if (matrix.size() == 0)
		return vec;
	int top = 0;
	int bottom = matrix.size() - 1;
	int left = 0;
	int right = matrix[0].size() - 1;
	int size = matrix.size() * matrix[0].size();
	while (vec.size() < size) {
		//left to right
		for (int i = left; i <= right && vec.size() < size; i++)
			vec.push_back(matrix[top][i]);
		top++;
		//top,right to bottom
		for(int i = top; i <= bottom && vec.size() < size ; i++)
			vec.push_back(matrix[i][right]);
		right--;
		//bottom,left to right
		for (int i = right; i >= left && vec.size() < size; i--)
			vec.push_back(matrix[bottom][i]);
		bottom--;
		//bottom-right to up
		for (int i = bottom; i >= top && vec.size() < size; i--)
			vec.push_back(matrix[i][left]);
		left++;
	}
	return vec;
}

int main()
{
	vector<vector<int>> vec = { {1,2,3},{4,5,6},{7,8,9} };
	vector<int> vv = spiralOrder(vec);
	for (auto item : vv) {
		cout << item << " ";
	}


	return 0;
}