
#ifndef __kruskal_h__
#define __kruskal_h__

#include "common.h"

class krus_Edge {
public:
    int src, dest, weight;
};

class krus_Graph {
public:
    int V, E;
    vector<krus_Edge> edges;

    krus_Graph(int V, int E) {
        this->V = V;
        this->E = E;
    }

    void addEdge(int u, int v, int w) {
        krus_Edge edge = {u, v, w};
        edges.push_back(edge);
    }

    int find(int parent[], int i) {
        if (parent[i] == -1)
            return i;
        return find(parent, parent[i]);
    }

    void Union(int parent[], int x, int y) {
        int xset = find(parent, x);
        int yset = find(parent, y);
        parent[xset] = yset;
    }

    void kruskalMST() {
        vector<krus_Edge> result;
        sort(edges.begin(), edges.end(),
             [](krus_Edge a, krus_Edge b) { return a.weight < b.weight; });

        int* parent = new int[V];
        fill(parent, parent + V, -1);

        for (krus_Edge edge : edges) {
            int x = find(parent, edge.src);
            int y = find(parent, edge.dest);

            if (x != y) {
                result.push_back(edge);
                Union(parent, x, y);
            }
        }

        cout << "Edges in the MST:" << endl;
        for (krus_Edge edge : result)
            cout << edge.src << " -- " << edge.dest << " == " << edge.weight << endl;
    }
};
 


#endif