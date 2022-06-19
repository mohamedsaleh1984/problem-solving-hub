#include <iostream>
#include <vector>
#include <map>
using namespace std;

class HamiltonianCycle {
public:
	HamiltonianCycle(vector<vector<int>> matrix) {
		this->adjacencyMatrix = matrix;
		this->hamiltonianPath.resize(matrix.size());
		this->numOfVertexes = matrix.size();
	}

	void slove() {
		this->hamiltonianPath[0] = 0;
		if (findFeasibleSolution(1))
			showHamiltonianPath();
		else
			cout << "No feasible solutions";
	}

private:
	int numOfVertexes;
	vector<int> hamiltonianPath;
	vector<vector<int>> adjacencyMatrix;


	bool areStartEndEqual(int position) {
		return adjacencyMatrix[hamiltonianPath[position - 1]][hamiltonianPath[0]] == 1;
	}

	bool findFeasibleSolution(int position) {
		if (position == numOfVertexes) {
			if (areStartEndEqual(position)) {
				return true;
			}
			else {
				return false;
			}
		}

		for (int vertexIndex = 1; vertexIndex < numOfVertexes; ++vertexIndex) {
			if (isFeasible(vertexIndex, position)) {
				hamiltonianPath[position] = vertexIndex;

				if (findFeasibleSolution(position + 1)) {
					return true;
				}

				// BACKTRACK !!
			}
		}
		return false;
	}

	bool isFeasible(int vertexIndex, int actualPosition) {
		//first criteria: whether two nodes are connected?
		if (adjacencyMatrix[hamiltonianPath[actualPosition - 1]][vertexIndex] == 0)
			return false;

		//second criteria: Whether we have the vertex in tha path
		for (int i = 0; i < actualPosition; i++) {
			if (hamiltonianPath[i] == vertexIndex) {
				return false;
			}
		}
		return true;
	}

	void showHamiltonianPath() {
		cout << "Hamiltonian cycle: ";
		for (auto elm : this->hamiltonianPath)
			cout << elm << " ";
		cout << this->hamiltonianPath[0];
	}
};


int main()
{ 

}
 