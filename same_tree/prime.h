
#ifndef __prime_h__
#define __prime_h__
#include "common.h"

#define INF 0x3f3f3f3f


class prime_Graph {
    int V;
    list< pair<int, int> >* adj;

public:
    prime_Graph(int V);
    void addEdge(int u, int v, int w);
    void primMST();
};

prime_Graph::prime_Graph(int V) {
    this->V = V;
    adj = new list<iPair>[V];
}

void prime_Graph::addEdge(int u, int v, int w) {
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void prime_Graph::primMST() {
    priority_queue<iPair, vector<iPair>, greater<iPair> > pq;
    int src = 0;
    vector<int> key(V, INF);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);

    pq.push(make_pair(0, src));
    key[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        for (auto i = adj[u].begin(); i != adj[u].end(); ++i) {
            int v = (*i).first;
            int weight = (*i).second;

            if (!inMST[v] && key[v] > weight) {
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }

    for (int i = 1; i < V; ++i)
        cout << parent[i] << " - " << i << endl;
}

#endif