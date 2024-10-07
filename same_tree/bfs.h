#ifndef __bfs.h__
#define __bfs.h__

#include "common.h"

class bfs_Graph {
    int V; 
    list<int>* adj;

public:
    bfs_Graph(int V);
    void addEdge(int v, int w);
    void BFS(int s);
};

bfs_Graph::bfs_Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void bfs_Graph::addEdge(int v, int w) {
    adj[v].push_back(w); 
}

void bfs_Graph::BFS(int s) {
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++) visited[i] = false;

    queue<int> q;
    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
        s = q.front();
        cout << s << " ";
        q.pop();

        for (auto i = adj[s].begin(); i != adj[s].end(); ++i) {
            if (!visited[*i]) {
                visited[*i] = true;
                q.push(*i);
            }
        }
    }
}
#endif
