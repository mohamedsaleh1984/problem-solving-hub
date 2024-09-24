#include <iostream>
#include <stdio.h>
#include <stack>
#include <queue>
#include <vector>
#include <utility> 
#include <unordered_map>
#include <map>
using namespace std;

class GraphNode {
public:
	GraphNode(int name) {
		this->name = name;
		this->weight = 0;
	}
	GraphNode(int name, int Weight) {
		this->name = name;
		this->weight = Weight;
	}
	int getName() {
		return this->name;
	}

	vector<int> getAdjacent() {
		return adjacentNodes;
	}
	
	void addAdjacent(int newNeighbor) {
		this->adjacentNodes.push_back(newNeighbor);
	}
	bool hasNeighbor() {
		return this->adjacentNodes.size() > 0;
	}

private:
	int name;
	int weight;
	vector<int> adjacentNodes;
};

class DirectedGraph {
public:

	void AddNode(int nodeName) {
		if (this->Nodes.find(nodeName) == this->Nodes.end()) {
			GraphNode fn(nodeName, 0);
			this->Nodes.insert({ nodeName, fn });
		}
	}
	//Check is there a linkn between two nodes
	bool IsThereLink(int from, int to)
	{
		for (size_t i = 0; i < _links.size(); i++)
		{
			tuple<int, int,int> item = _links[i];
			if ( get<0>(item) == from &&  get<1>(item)== to)
				return true;
		}

		return false;
	}

	//Add Link between two nodes
	void AddLink(int fromNode, int toNode, int weight) {
		if (this->Nodes.find(fromNode) == this->Nodes.end() || this->Nodes.find(toNode) == this->Nodes.end()) {
			return;
		}

		if (!IsThereLink(fromNode, toNode)) {

			tuple<int, int,int> newLink = { fromNode,toNode,weight };
			_links.push_back(newLink);

			Nodes.at(fromNode).addAdjacent(toNode);
		}
	}

	//Show Graphs (Nodes, Links)
	void ShowGraph() {
		//Show Nodes...
		cout << "Nodes...\n";
		for (auto it = Nodes.begin(); it != Nodes.end(); ++it) {
			pair<int, GraphNode> n = *it;
			cout << n.first << endl;
		}

		cout << "links ...\n";
		for (size_t i = 0; i < _links.size(); i++)
		{
			tuple<int, int,int> item = _links[i];
			cout << "from " << get<0>(item) << " to " << get<1>(item) << " weight " <<get<2>(item) << endl;
		}

		cout << "Neighbours Nodes...\n";
		for (auto it = Nodes.begin(); it != Nodes.end(); ++it) {
			pair<int, GraphNode> n = *it;
			cout << "Node Name = " << n.first << " has neighbours " << n.second.hasNeighbor() << " =>";
			pv(getNeighboursOf(n.first));
			cout << "\n";
		}
	}

	void pv(vector<int> vec) {
		for (int i = 0; i < vec.size(); i++)
		{
			cout << vec[i] << " ";
		}
	}

	vector<int> getNeighboursOf(int nodeName) {
		return Nodes.at(nodeName).getAdjacent();
	}

private:
	std::unordered_map<int, GraphNode> Nodes;
	std::vector<tuple<int, int,int>> _links;//edge
};

class DFS {
public:
	DFS(DirectedGraph dg) {
		this->_dg = dg;
	}

	void Traverse(int StartNode) {
		q.push(StartNode);

		while (!q.empty())
		{
			int popedNode = q.front();;
			q.pop();
			cout << ".." <<  popedNode << endl;
			MarkNode(popedNode);

			AddUnvisitedAdjacentNodes(this->_dg.getNeighboursOf(popedNode));


		}
		
	}

	void viewGraph() {
		this->_dg.ShowGraph();
	}

	bool IsVisited(int nodeName)
	{
		return find(visitedNodes.begin(), visitedNodes.end(), nodeName) != visitedNodes.end();
	}
	void AddUnvisitedAdjacentNodes(vector<int> adjacent)
	{
		for (size_t i = 0; i < adjacent.size(); i++){
			if (IsVisited(adjacent[i])) {
				q.push(adjacent[i]);
			}
		}
	}
private:
	DirectedGraph _dg;
	vector<int> visitedNodes;
	queue<int> q;
	void MarkNode(int nodeName) {
		visitedNodes.push_back(nodeName);
	}
};

int main()
{
	DirectedGraph  cls;
	cls.AddNode(1);
	cls.AddNode(2);
	cls.AddNode(3);
	cls.AddNode(4);
	cls.AddNode(5);
	
	cls.AddLink(1, 2, 1);
	cls.AddLink(1, 3, 10);
	cls.AddLink(2, 3, 3);
	cls.AddLink(3, 4, 1);
	cls.AddLink(4, 5, 1);
	cls.AddLink(2, 5, 1);
	

	DFS* dfs = new DFS(cls);
	dfs->viewGraph();

	dfs->Traverse(1);



	return 0;
}
