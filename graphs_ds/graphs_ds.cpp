#include <iostream>
#include <stdio.h>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>
#include <algorithm>
#include <map>
using namespace std;

class GraphNode
{
public:

	GraphNode(size_t name)
	{
		this->name = name;
		this->weight = 0;
	}
	GraphNode(size_t name, size_t Weight)
	{
		this->name = name;
		this->weight = Weight;
	}
	size_t getName()
	{
		return this->name;
	}

	vector<size_t> getAdjacent()
	{
		return adjacentNodes;
	}

	void addAdjacent(size_t newNeighbor)
	{
		vector<size_t>::iterator flag = find(adjacentNodes.begin(), adjacentNodes.end(), newNeighbor);
		if (flag == adjacentNodes.end())
		{
			this->adjacentNodes.push_back(newNeighbor);
		}
	}
	bool hasNeighbor()
	{
		return this->adjacentNodes.size() > 0;
	}

private:
	size_t name;
	size_t weight;
	vector<size_t> adjacentNodes;
};

class DirectedGraph
{
public:
	void AddNode(size_t nodeName)
	{
		if (this->Nodes.find(nodeName) == this->Nodes.end())
		{
			GraphNode fn(nodeName, 0);
			this->Nodes.insert({nodeName, fn});
		}
	}

	void AddNodes(vector<size_t> nodes)
	{
		for (size_t i = 0; i < nodes.size(); i++)
		{
			GraphNode fn(nodes[i], 0);
			this->Nodes.insert({nodes[i], fn});
		}
	}
	// Check is there a linkn between two nodes
	bool IsThereLink(size_t from, size_t to)
	{
		for (size_t i = 0; i < _edges.size(); i++)
		{
			tuple<size_t, size_t, size_t> item = _edges[i];
			if (get<0>(item) == from && get<1>(item) == to)
				return true;
		}

		return false;
	}

	// Add Link between two nodes
	void addEdge(size_t fromNode, size_t toNode, size_t weight)
	{
		if (this->Nodes.find(fromNode) == this->Nodes.end() || this->Nodes.find(toNode) == this->Nodes.end())
		{
			return;
		}

		if (!IsThereLink(fromNode, toNode))
		{

			tuple<size_t, size_t, size_t> newLink = {fromNode, toNode, weight};
			_edges.push_back(newLink);

			Nodes.at(fromNode).addAdjacent(toNode);
		}
	}

	// Show Graphs (Nodes, Links)
	void ShowGraph()
	{
		// Show Nodes...
		cout << "Nodes...\n";
		for (auto it = Nodes.begin(); it != Nodes.end(); ++it)
		{
			pair<size_t, GraphNode> n = *it;
			cout << n.first << " ";
		}

		cout << "links ...\n";
		for (size_t i = 0; i < _edges.size(); i++)
		{
			tuple<size_t, size_t, size_t> item = _edges[i];
			cout << "from " << get<0>(item) << " to " << get<1>(item) << " weight " << get<2>(item) << endl;
		}

		cout << "Neighbours Nodes...\n";
		for (auto it = Nodes.begin(); it != Nodes.end(); ++it)
		{
			pair<size_t, GraphNode> n = *it;
			cout << "Node Name = " << n.first << " has neighbours " << n.second.hasNeighbor() << " =>";
			pv(getNeighboursOf(n.first));
			cout << "\n";
		}
	}

	void pv(vector<size_t> vec)
	{
		for (size_t i = 0; i < vec.size(); i++)
		{
			cout << vec[i] << " ";
		}
	}

	vector<size_t> getNeighboursOf(size_t nodeName)
	{
		return Nodes.at(nodeName).getAdjacent();
	}

	size_t getNodesCount()
	{
		return this->Nodes.size();
	}



private:
	std::unordered_map<size_t, GraphNode> Nodes;
	std::vector<tuple<size_t, size_t, size_t>> _edges; // edge
};

class GraphTraverse
{
public:
	GraphTraverse(DirectedGraph dg)
	{
		this->_dg = dg;
	}

	void BFSTraverse(size_t StartNode)
	{
		cout << "BFS Algo" << endl;
		cout << "***********************" << endl;

		queue<size_t> q;
		vector<bool> visited(_dg.getNodesCount(), false);

		// cout << "visiting node " << StartNode << endl;
		q.push(StartNode);
		visited[StartNode - 1] = true;
		cout << StartNode << " ";

		while (!q.empty())
		{
			size_t popedNode = q.front();

			// cout << "\tremoving node " << popedNode << endl;
			q.pop();

			vector<size_t> neighbours = this->_dg.getNeighboursOf(popedNode);
			for (size_t i = 0; i < neighbours.size(); i++)
			{

				if (!visited[neighbours[i] - 1])
				{
					//	cout << "\tmark node " << popedNode << " visited " << endl;
					visited[neighbours[i] - 1] = true;
					q.push(neighbours[i]);
					cout << neighbours[i] << " ";
				}
			}
		}

		cout << endl;
		cout << "***********************" << endl;
	}

	void DFSTraverse(size_t StartNode)
	{
		cout << "DFS Algo" << endl;
		cout << "***********************" << endl;

		vector<bool> visited(_dg.getNodesCount(), false);
		visited[StartNode - 1] = true;

		stack<size_t> s;
		s.push(StartNode);
		cout << StartNode << " ";
		while (!s.empty())
		{
			size_t popedNode = s.top();
			// cout << "visiting node " << popedNode << endl;

			// cout << "\tremoving node " << popedNode << endl;
			s.pop();

			vector<size_t> neighbours = this->_dg.getNeighboursOf(popedNode);
			for (size_t i = 0; i < neighbours.size(); i++)
			{
				if (!visited[neighbours[i] - 1])
				{
					// cout << "\tmark node " << popedNode << " visited " << endl;
					visited[neighbours[i] - 1] = true;
					s.push(neighbours[i]);
					cout << neighbours[i] << " ";
				}
			}
		}

		cout << endl;
		cout << "***********************" << endl;
	}


	void viewGraph()
	{
		this->_dg.ShowGraph();
	}

private:
	DirectedGraph _dg;
};

int main()
{
	std::ios_base::sync_with_stdio(false);

	DirectedGraph cls;
	vector<size_t> vec = {1, 2, 3, 4, 5};
	cls.AddNodes(vec);

	cls.addEdge(1, 2, 1);
	cls.addEdge(1, 3, 10);
	cls.addEdge(2, 3, 3);
	cls.addEdge(3, 4, 1);
	cls.addEdge(4, 5, 1);
	cls.addEdge(2, 5, 1);

	GraphTraverse *t = new GraphTraverse(cls);
	t->BFSTraverse(1);
	t->DFSTraverse(1);
	return 0;
}
