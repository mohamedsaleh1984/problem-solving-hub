#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <utility> // for std::pair
#include <cctype>  // for std::isdigit
#include <unordered_map>
using namespace std;

//https://leetcode.com/problems/find-if-path-exists-in-graph
//Runtime 795ms Beats 9.57 %
// 05/13/2025

class Solution {
public:
	bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
		map<int, vector<int>> neighbors;
		for (int i = 0; i < edges.size(); i++) {
			neighbors[edges[i][0]].push_back(edges[i][1]);
			neighbors[edges[i][1]].push_back(edges[i][0]);
		}

		vector<bool> visited(n, false);
		stack<int> nav;
		nav.push(source);
		visited[source] = true;


		while (!nav.empty()) {
			int curr_node = nav.top(); nav.pop();
			visited[curr_node] = true;

			if (curr_node == destination) {
				return true;
			}

			vector<int> neigh = neighbors[curr_node];

			for (int i = 0; i < neigh.size(); i++) {
				if (!visited[neigh[i]]) {
					visited[neigh[i]] = true;
					nav.push(neigh[i]);
				}
			}
		}
		return false;
	}
};
 
/// <summary>
/// read file in format 
/// {{199998,199999},{199997,199998},...} and return vector of vector
/// </summary>
/// <returns></returns>
static vector<vector<int>>  read_vector_vector(string filename) {
	char open_bracket = '{';
	char close_bracket = '}';

	string line;
	ifstream inputFile(filename);
	vector<vector<int>> matrix;

	if (!inputFile.is_open()) {
		cerr << "Could not open the file." << endl;
		return matrix;
	}

	if (inputFile && std::getline(inputFile, line)) {
		std::stringstream ss(line);
		char ch;
		int a, b;
		char tmp;
		ss >> tmp;
		while (ss >> ch) {
			if (ch == open_bracket) {
				if (ss >> a >> ch && ch == ',' && ss >> b >> ch && ch == close_bracket) {
					vector<int> c = { a,b };
					matrix.push_back(c);
				}
				ss >> tmp;
			}
		}
		inputFile.close();
	}

	return matrix;
}


int main()
{
	vector<vector<int>> edges_v0 = { {0,7},{0,8},{6,1},{2,0},{0,4},{5,8},{4,7},{1,3},{3,5},{6,5} };
	vector<vector<int>> edges_v1 = { {0,1},{0,2},{3,5},{5,4},{4,3} };
	//vector<vector<int>> edges_v2 = { {4,3},{1,4},{4,8},{1,7},{6,4},{4,2},{7,4},{4,0},{0,9},{5,4} };

	Solution s;
	cout << (s.validPath(6, edges_v1, 0, 5) ? "True" : "False") << endl;
	cout << (s.validPath(9, edges_v0, 0, 6) ? "True" : "False") << endl;
	vector<vector<int>> matrix = read_vector_vector("20000_edge.txt");
	cout << (s.validPath(200000, matrix, 0, 199999) ? "True" : "False") << endl;
	vector<vector<int>> matrix2 = read_vector_vector("1000001_edges.txt");
	cout << (s.validPath(100001, matrix2, 0, 100000) ? "True" : "False") << endl;

	return 0;
}
