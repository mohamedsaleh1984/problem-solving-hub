#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;

class MazeSolver {
private:
	vector<vector<int>> mazeBoard;
	vector<vector<int>> solutionTable;
	const int SIZE = 5;

	bool solveMaze(int x, int y) {
		if (isFinished(x, y))
			return true;

		if (isValid(x, y)) {
			solutionTable[x][y] = 1;
			//move one row down
			if (solveMaze(x + 1, y)) {
				return true;
			}
			if (solveMaze(x, y + 1)) {
				return true;
			}
			//BACKTRACK
			solutionTable[x][y] = 0;
		}
		return false;
	}

	bool isFinished(int x, int y) {
		//reached to rightbottom corner cell which is the target.
		if (x == SIZE - 1 && y == SIZE - 1)
		{
			//Mark in the solution table and return 
			solutionTable[x][y] = 1;
			return true;
		}
		return false;
	}

	bool isValid(int x, int y) {
		//outside the board boundries
		if (x < 0 && x >= SIZE)
			return false;
		if (y < 0 && y >= SIZE)
			return false;
		if (mazeBoard[x][y] != 1)
			return false;
		return true;
	}

	void printSolution() {
		cout << "Maze-Board" << endl;
		for (int x = 0; x < SIZE; x++) {
			for (int y = 0; y < SIZE; y++)
				cout << setw(2) << mazeBoard[x][y] << " ";
			cout << endl;
		}
		cout << endl;
		cout << "Solution" << endl;
		for (int x = 0; x < SIZE; x++) {
			for (int y = 0; y < SIZE; y++) {
				cout << setw(2) << solutionTable[x][y];
			}
			cout << endl;
		}

	}
public:
	MazeSolver(vector<vector<int>> board) {
		this->mazeBoard = board;
		this->solutionTable.resize(SIZE, std::vector<int>(SIZE));
	}

	void solve() {
		if (solveMaze(0, 0)) {
			printSolution();
		}
		else {
			cout << "No Solution Found...";
		}
	}
};

int main()
{
    std::cout << "Hello World!\n";
}