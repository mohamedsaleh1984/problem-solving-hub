#include <iostream>


class Represent_Graph_Adjacency_Matrix {

private:
	int vertices;
	int adjacency_matrix[10][10];
public:
	void makeEdge(int to, int from, int edge){
		adjacency_matrix[to][from] = edge;	
	}

	int getEdge(int to, int from){		
		return adjacency_matrix[to][from];
	}
};

int main()
{

}
