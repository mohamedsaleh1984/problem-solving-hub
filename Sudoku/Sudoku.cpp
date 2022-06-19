#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;

class SudokuSolver {
private:
	const int BOARD_SIZE = 9;
	const int MIN_NUMBER = 1;
	const int MAX_NUMBER = 9;
	const int BOX_SIZE = 3;
	vector<vector<int>> sudokuBoard;
public:
	SudokuSolver(vector<vector<int>> board) {
		this->sudokuBoard = board;
	}

	void solveSudoku() {
		if (solve(0, 0)) {
			printSolution();
		}
		else
		{
			cout << "No Solution..." << endl;
		}
	}

	bool valid(int colIndex, int rowIndex, int actualNumber) {
		if (!isValidRow(rowIndex, actualNumber))
			return false;

		if (!isValidColumn(colIndex, actualNumber))
			return false;

		if (!IsValidBox(rowIndex, colIndex, actualNumber))
			return false;

		return true;
	}

	bool isValidRow(int rowIndex, int actualNumber) {
		for (int i = 0; i < BOARD_SIZE; ++i) {
			if (sudokuBoard[rowIndex][i] == actualNumber)
				return false;
		}
		return true;
	}

	bool isValidColumn(int colIndex, int actualNumber) {
		for (int i = 0; i < BOARD_SIZE; ++i) {
			if (sudokuBoard[i][colIndex] == actualNumber)
				return false;
		}
		return true;
	}

	bool IsValidBox(int rowIndex, int colIndex, int actualNumber)
	{
		int boxRowOffset = (colIndex / 3) * BOX_SIZE;
		int boxColumnOffset = (rowIndex / 3) * BOX_SIZE;

		for (int i = 0; i < BOX_SIZE; i++) {
			for (int j = 0; j < BOX_SIZE; j++) {
				if (actualNumber == sudokuBoard[boxRowOffset + i][boxColumnOffset + j])
					return false;
			}
		}
		return true;
	}

	bool solve(int rowIndex, int colIndex) {
		//reached to a solution
		if (rowIndex == BOARD_SIZE && ++colIndex == BOARD_SIZE)
			return true;

		//since we solve the problem column wise we need to reset the 
		// iterator
		if (rowIndex == BOARD_SIZE)
			rowIndex = 0;

		//ignore non-empty cells
		if (sudokuBoard[rowIndex][colIndex] != 0)
			return solve(rowIndex + 1, colIndex);

		//
		for (int number = MIN_NUMBER; number <= MAX_NUMBER; number++) {
			if (valid(rowIndex, colIndex, number)) {
				//Place a number
				sudokuBoard[rowIndex][colIndex] = number;
				//Check the next row
				if (solve(rowIndex + 1, colIndex)) {
					return true;
				}
				//BACKTRACK
				sudokuBoard[rowIndex][colIndex] = 0;
			}
		}

		return false;
	}

	void printSolution() {
		for (int x = 0; x < BOARD_SIZE; x++) {
			if (x % 3 == 0)
				cout << " " << endl;

			for (int y = 0; y < BOARD_SIZE; y++) {
				if (y % 3 == 0)
					cout << " ";
				cout << setw(2) << sudokuBoard[x][y];
			}
			cout << endl;
		}
	}
};

//https://leetcode.com/problems/sudoku-solver/
//TODO:Revamp...
class Solution {
private:
	const int BOARD_SIZE = 9;
	const int BOX_SIZE = 3;

	bool solve(int rowIndx, int colIndx, vector<vector<char>>& board) {
		//reached to a solution
		if (rowIndx == BOARD_SIZE && ++colIndx == BOARD_SIZE)
			return true;

		//since we solve the problem column wise we need to reset the 
		// iterator
		if (rowIndx == BOARD_SIZE)
			rowIndx = 0;

		//ignore non-empty cells
		if (board[rowIndx][colIndx] != '.')
			return solve(rowIndx + 1, colIndx, board);

		for (char num = '1'; num <= '9'; num++)
		{
			if (IsValidPlacement(rowIndx, colIndx, num, board))
			{
				//Place a number
				board[rowIndx][colIndx] = num;
				//Check the next row
				if (solve(rowIndx + 1, colIndx, board)) {
					return true;
				}
				//BACKTRACK
				board[rowIndx][colIndx] = '.';
			}
		}
		return false;
	}

	bool IsValidPlacement(int rowIndx, int colIndx, char numberToTry, vector<vector<char>>& board) {
		if (!isValidRow(rowIndx, numberToTry, board))
			return false;

		if (!isValidColumn(colIndx, numberToTry, board))
			return false;

		if (!isValidBox(rowIndx, colIndx, numberToTry, board))
			return false;

		return true;
	}

	bool isValidRow(int rowIndex, char numberToPlace, vector<vector<char>>& board) {
		for (int i = 0; i < BOARD_SIZE; ++i)
		{
			if (board[rowIndex][i] == numberToPlace)
				return false;
		}
		return true;
	}

	bool isValidColumn(int colIndex, char numberToPlace, vector<vector<char>>& board) {
		for (int i = 0; i < BOARD_SIZE; ++i)
		{
			if (board[i][colIndex] == numberToPlace)
				return false;
		}
		return true;
	}

	bool isValidBox(int rowIdx, int colIdx, char numberToPlace, vector<vector<char>>& board) {
		int boxRowOffset = (colIdx / 3) * BOX_SIZE;
		int boxColumnOffset = (rowIdx / 3) * BOX_SIZE;

		for (int i = 0; i < BOX_SIZE; i++) {
			for (int j = 0; j < BOX_SIZE; j++) {
				if (numberToPlace == board[boxRowOffset + i][boxColumnOffset + j])
					return false;
			}
		}
		return true;
	}
public:
	void solveSudoku(vector<vector<char>>& board) {
		solve(0, 0, board);
	}
};





int main()
{
	vector<vector<char>> board = { {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
		{ '6','.','.','1','9','5','.','.','.' },
		{ '.','9','8','.','.','.','.','6','.' },
		{ '8','.','.','.','6','.','.','.','3' },
		{ '4','.','.','8','.','3','.','.','1' },
		{ '7','.','.','.','2','.','.','.','6' },
		{ '.','6','.','.','.','.','2','8','.' },
		{ '.','.','.','4','1','9','.','.','5' }, 
		{ '.','.','.','.','8','.','.','7','9' } };
	Solution s;
	s.solveSudoku(board);

	for (size_t i = 0; i < 9; i++)
	{
		for (size_t j = 0; j < 9; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
