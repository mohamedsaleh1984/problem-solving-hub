#include <iostream>
#include <vector>
using namespace std;
/*
Given a positive integer n, generate an n x n matrix filled 
with elements from 1 to n2 in spiral order.
*/
vector<vector<int>> generateMatrix(int n) {
	vector<vector<int>> matrix;
	vector<int> temp;
	for (int i = 0; i < n; i++)
		temp.push_back(0);
	for (int i = 0; i < n; i++) {
		matrix.push_back(temp);
	}
	int left = 0;
	int top = 0;
	int right = n - 1;
	int bottom = n - 1;
	int size = pow(n, 2);
	int elements = 0;
	int ith = 1;

	while (elements < size) {
		//left to right 
		for (int i = left; i <= right && elements < size; i++) {
			matrix[top][i] = ith;// pow(ith, 2);
			elements++;
			ith++;
		}
		top++;
		//top,right to bottom, right
		for (int i = top; i <= bottom && elements < size; i++) {
			matrix[i][right] = ith;// pow(ith, 2);
			elements++;
			ith++;
		}
		right--;
		//right,bottom to left,bottom
		for (int i = right; i >= left && elements < size; i--) {
			matrix[bottom][i] = ith;// pow(ith, 2);
			elements++;
			ith++;
		}
		bottom--;
		//bottom,right to up
		for (int i = bottom; i >= top && elements < size; i--) {
			matrix[i][left] = ith;// pow(ith, 2);
			elements++;
			ith++;
		}
		left++;
	}
	return matrix;
}

int main()
{
	vector<vector<int>> result = generateMatrix(3);
	for (auto vec : result) {
		for (auto r : vec) {
			cout << r << " ";
		}
		cout << "\n";
	}
}
