#include <iostream>
#include <vector>
using namespace std;

//https://leetcode.com/problems/set-matrix-zeroes/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> points; 
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    points.push_back({ i,j });
                }
            }
        }

        for (int i = 0; i < points.size(); i++) {
            setRowZeros(matrix, points[i][0]);
            setColumnZeros(matrix, points[i][1]);
        }
    }

    void setRowZeros(vector<vector<int>>& matrix, int row) {
        for (int i = 0; i < matrix[0].size(); i++) {
            matrix[row][i] = 0;
        }
    }

    void setColumnZeros(vector<vector<int>>& matrix, int column) {
        for (int i = 0; i < matrix.size(); i++) {
            matrix[i][column] = 0;
        }
    }
};
int main()
{
	vector< vector<int>> matrix = { {1, 1, 1},{1, 0, 1},{1, 1, 1}};
	
	return 0;
}