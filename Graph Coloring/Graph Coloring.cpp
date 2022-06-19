#include <iostream>
#include <vector>
#include <map>
using namespace std;

class GraphColoring {
public:
	GraphColoring(vector<vector<int>> matrix, int numOfColors) {
		this->adjacencyMatrix = matrix;
		this->numOfColors = numOfColors;
		this->numOfVertexes = matrix.size();
		this->colors.resize(numOfVertexes);
	}

	void solve() {
		if (colorVertex(0)) {
			showResult();
		}
		else {
			cout << "No solution..";
		}
	}


private:
	int numOfVertexes;
	int numOfColors;
	vector<int> colors;
	vector<vector<int>> adjacencyMatrix;

	bool colorVertex(int nodeIndex) {
		if (nodeIndex == numOfVertexes)
			return true;
		//try colors
		for (int colorIndex = 1; colorIndex <= numOfColors; ++colorIndex)
		{
			if (isColorValid(nodeIndex, colorIndex)) {
				colors[nodeIndex] = colorIndex;

				if (colorVertex(nodeIndex + 1))
					return true;
			}
			//Backtrack !!
		}
		return false;
	}

	bool isColorValid(int nodeIndex, int colorIndex) {
		//connected and not the same color
		for (int i = 0; i < this->numOfVertexes; i++) {
			if (adjacencyMatrix[nodeIndex][i] == 1 && colorIndex == colors[i]) {
				return false;
			}
		}
		return true;
	}

	void showResult() {
		for (int i = 0; i < numOfVertexes; i++)
			cout << "Node " << (i + 1) << " has color index: " << colors[i] << endl;
	}
};

int main()
{

}
