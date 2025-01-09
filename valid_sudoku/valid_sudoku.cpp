#include "../common.h"

/*
https://leetcode.com/problems/valid-sudoku/
Runtime: 28 ms, faster than 64.82% of C++ online submissions for Valid Sudoku.
Memory Usage: 19.4 MB, less than 49.93% of C++ online submissions for Valid Sudoku.

*/
class Solution
{
public:
	bool isValidSudoku(vector<vector<char>> &board)
	{
		return isValidRows(board) && isValidColumns(board) && isValidSquares(board);
	}

	bool isValidRows(vector<vector<char>> &board)
	{
		for (int iRow = 0; iRow < 9; iRow++)
		{
			set<char> mySet;
			for (int iCol = 0; iCol < 9; iCol++)
			{
				if (board[iRow][iCol] != '.')
				{
					auto pos = mySet.find(board[iRow][iCol]);
					if (pos != mySet.end())
					{
						return false;
					}
					else
					{
						mySet.insert(board[iRow][iCol]);
					}
				}
			}
		}
		return true;
	}

	bool isValidColumns(vector<vector<char>> &board)
	{
		for (int iRow = 0; iRow < 9; iRow++)
		{
			set<char> mySet;
			for (int iCol = 0; iCol < 9; iCol++)
			{
				if (board[iCol][iRow] != '.')
				{
					auto pos = mySet.find(board[iCol][iRow]);
					if (pos != mySet.end())
					{
						return false;
					}
					else
					{
						mySet.insert(board[iCol][iRow]);
					}
				}
			}
		}
		return true;
	}

	bool isValidSquares(vector<vector<char>> &board)
	{
		vector<set<char>> Squares(9);
		for (int iRow = 0; iRow < 9; iRow++)
		{
			for (int iCol = 0; iCol < 9; iCol++)
			{
				if (board[iRow][iCol] != '.')
				{
					int index = getIndex(iRow, iCol);
					auto pos = Squares[index].find(board[iRow][iCol]);
					if (pos != Squares[index].end())
					{
						return false;
					}
					else
					{
						Squares[index].insert(board[iRow][iCol]);
					}
				}
			}
		}
		return true;
	}

	int getIndex(int row, int col)
	{
		if (row >= 0 && row <= 2 && col >= 0 && col <= 2)
			return 0;
		if (row >= 0 && row <= 2 && col >= 3 && col <= 5)
			return 1;
		if (row >= 0 && row <= 2 && col >= 6 && col <= 8)
			return 2;
		if (row >= 3 && row <= 5 && col >= 0 && col <= 2)
			return 3;
		if (row >= 3 && row <= 5 && col >= 3 && col <= 5)
			return 4;
		if (row >= 3 && row <= 5 && col >= 6 && col <= 8)
			return 5;
		if (row >= 6 && row <= 8 && col >= 0 && col <= 2)
			return 6;
		if (row >= 6 && row <= 8 && col >= 3 && col <= 5)
			return 7;
		if (row >= 6 && row <= 8 && col >= 6 && col <= 8)
			return 8;

		return -1;
	}
};

int main()
{
	vector<vector<char>> board2 = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
								   {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
								   {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
								   {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
								   {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
								   {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
								   {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
								   {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
								   {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

	vector<vector<char>> board = {{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
								  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
								  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
								  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
								  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
								  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
								  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
								  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
								  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

	Solution cls = Solution();
	cout << cls.isValidSudoku(board);

	return 0;
}
