#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;

//https://leetcode.com/problems/sudoku-solver/
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
		for (int i = 0; i < BOARD_SIZE; ++i) {
			if (sudokuBoard[i][rowIndex] == actualNumber)
				return false;
		}
		for (int i = 0; i < BOARD_SIZE; ++i) {
			if (sudokuBoard[colIndex][i] == actualNumber)
				return false;
		}

		//if the given number is already in the box: the number cannot be part of the solution
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

		//since we solve the problem column wize we need to reset the 
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


int main()
{
	vector<vector<int>> sudokuTable = {
							{3,0,6,5,0,8,4,0,0},
							{5,2,0,0,0,0,0,0,0},
							{0,8,7,0,0,0,0,3,1},
							{0,0,3,0,1,0,0,8,0},
							{9,0,0,8,6,3,0,0,5},
							{0,5,0,0,9,0,6,0,0},
							{1,3,0,0,0,0,2,5,0},
							{0,0,0,0,0,0,0,7,4},
							{0,0,5,2,0,6,3,0,0}
	};
	SudokuSolver ss(sudokuTable);
	ss.solveSudoku();

	return 0;
}
