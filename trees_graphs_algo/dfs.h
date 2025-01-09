#ifndef __dfs_h__
#define __dfs_h__

#include "common.h"

class dfs_Graph {
    int V;
    list<int>* adj;
    void DFSUtil(int v, bool visited[]);

public:
    dfs_Graph(int V);
    void addEdge(int v, int w);
    void DFS(int v);
};

dfs_Graph::dfs_Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void dfs_Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void dfs_Graph::DFSUtil(int v, bool visited[]) {
    visited[v] = true;
    cout << v << " ";

    for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

void dfs_Graph::DFS(int v) {
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++) visited[i] = false;

    DFSUtil(v, visited);
}

#endif