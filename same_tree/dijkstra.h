#ifndef __dijkstra_h__
#define __dijkstra_h__
#include "common.h"

class DGraph {
    int V;
    list< pair<int, int> >* adj;

public:
    DGraph(int V);
    void addEdge(int u, int v, int w);
    void dijkstra(int src);
};

DGraph::DGraph(int V) {
    this->V = V;
    adj = new list<iPair>[V];
}

void DGraph::addEdge(int u, int v, int w) {
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void DGraph::dijkstra(int src) {
    priority_queue<iPair, vector<iPair>, greater<iPair> > pq;
    vector<int> dist(V, INT_MAX);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto i = adj[u].begin(); i != adj[u].end(); ++i) {
            int v = (*i).first;
            int weight = (*i).second;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < V; ++i)
        cout << i << "\t\t" << dist[i] << endl;
}


#endif