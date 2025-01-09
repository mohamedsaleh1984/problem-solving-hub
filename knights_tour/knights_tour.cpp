#include "../common.h"

// horse in Chess
class KnightsTour
{
private:
	vector<vector<int>> solutionMaxtrix;
	vector<int> xMoves = {2, 1, -1, -2, -2, -1, 1, 2};
	vector<int> yMoves = {1, 2, 2, 1, -1, -2, -2, -1};
	const int BOARD_SIZE = 8;
	const int KNIGHT_MOVIES = 8;

	void initBoard()
	{
		for (int i = 0; i < BOARD_SIZE; i++)
		{
			solutionMaxtrix[i].resize(BOARD_SIZE);
			for (int j = 0; j < BOARD_SIZE; j++)
			{
				solutionMaxtrix[i][j] = INT_MIN;
			}
		}
	}

	void printSolution()
	{
		for (int i = 0; i < BOARD_SIZE; i++)
		{
			for (int j = 0; j < BOARD_SIZE; j++)
			{
				cout << setw(2) << solutionMaxtrix[i][j] << " ";
			}
			cout << endl;
		}
	}

	bool solve(int stepCounter, int x, int y)
	{
		if (stepCounter == BOARD_SIZE * BOARD_SIZE + 1)
		{
			return true;
		}

		for (int i = 0; i < KNIGHT_MOVIES; i++)
		{
			int newX = xMoves[i] + x;
			int newY = yMoves[i] + y;

			if (isValidMove(newX, newY))
			{
				solutionMaxtrix[newX][newY] = stepCounter;
				if (solve(stepCounter + 1, newX, newY))
				{
					return true;
				}
				// BACKTRACK
				solutionMaxtrix[newX][newY] = INT_MIN;
			}
		}
		return false;
	}

	bool isValidMove(int x, int y)
	{
		return x >= 0 && x <= BOARD_SIZE - 1 && y >= 0 && y <= BOARD_SIZE - 1 && solutionMaxtrix[x][y] == INT_MIN;
	}

public:
	KnightsTour()
	{
		this->solutionMaxtrix.resize(BOARD_SIZE);
		this->initBoard();
	}

	void solveKnightTour()
	{
		// Start Index of the Knight
		solutionMaxtrix[0][0] = 1;

		if (solve(2, 0, 0))
		{
			printSolution();
		}
		else
		{
			cout << "No feasible solution..." << endl;
		}
	}
};

int main()
{
	return 0;
}
