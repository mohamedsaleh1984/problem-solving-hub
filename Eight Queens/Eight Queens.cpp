#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;

class Queens {
public:
	Queens(int numOfQueens) {
		this->numOfQueens = numOfQueens;
		this->chessTable.resize(numOfQueens, vector<int>(numOfQueens));
	}
	void solve() {
		if (setQueen(0)) {
			printQueens();
		}
		else {
			cout << "no feasible solution" << endl;
		}
	}

private:
	int numOfQueens;
	vector<vector<int>> chessTable;

	bool isPlaceValid(int rowIndex, int colIndex) {

		if (!checkCurrentRow(rowIndex, colIndex))
			return false;

		if (!checkDiagonalsTopLeftRightBottom(rowIndex, colIndex))
			return false;

		if (!checkDiagonalsTopRightLeftBottom(rowIndex, colIndex))
			return false;

		return true;
	}

	bool checkCurrentRow(int rowIndex, int colIndex) {
		for (int i = 0; i < colIndex; i++) {
			if (chessTable[rowIndex][i] == 1)
				return false;
		}
		return true;
	}

	bool checkDiagonalsTopLeftRightBottom(int rowIndex, int colIndex) {
		for (int i = rowIndex, j = colIndex; i >= 0 && j >= 0; i--, j--) {
			if (chessTable[i][j] == 1)//there is a queen in the diagonal
				return false;
		}
		return true;
	}

	bool checkDiagonalsTopRightLeftBottom(int rowIndex, int colIndex) {
		for (int i = rowIndex, j = colIndex; i < numOfQueens && j >= 0; i++, j--) {
			if (chessTable[i][j] == 1)
				return false;
		}
		return true;
	}

	bool setQueen(int colIndex) {
		if (colIndex == numOfQueens)//found a solution
			return true;

		for (int rowIndex = 0; rowIndex < this->numOfQueens; rowIndex++) {
			if (isPlaceValid(rowIndex, colIndex)) {
				chessTable[rowIndex][colIndex] = 1;
				if (setQueen(colIndex + 1)) {
					return true;
				}
				//Backtracking
				chessTable[rowIndex][colIndex] = 0;
			}
		}
		return false;
	}

	void printQueens() {
		for (int i = 0; i < this->numOfQueens; i++) {
			for (int j = 0; j < this->numOfQueens; j++)
			{
				if (this->chessTable[i][j] == 1)
					cout << " * ";
				else
					cout << " - ";
			}
			cout << endl;
		}
		cout << endl;
	}
};

int main()
{
	Queens Q = Queens(4);
	Q.solve();
	return 0;
}