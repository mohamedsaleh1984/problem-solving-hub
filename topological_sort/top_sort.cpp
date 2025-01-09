#include "../common.h"

// C++ program to demonstrate Adjacency Matrix
// representation of undirected and unweighted graph

class T
{
    void addEdge(vector<vector<int>> &mat, int i, int j)
    {
        mat[i][j] = 1;
        mat[j][i] = 1; // Since the graph is undirected
    }

    void displayMatrix(vector<vector<int>> &mat)
    {
        int V = mat.size();
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
                cout << mat[i][j] << " ";
            cout << endl;
        }
    }

    // Function to perform DFS and topological sorting
    void topologicalSortUtil(int v, vector<vector<int>> &adj,
                             vector<bool> &visited,
                             stack<int> &Stack)
    {
        // Mark the current node as visited
        visited[v] = true;

        // Recur for all adjacent vertices
        for (int i : adj[v])
        {
            if (!visited[i])
                topologicalSortUtil(i, adj, visited, Stack);
        }

        // Push current vertex to stack which stores the result
        Stack.push(v);
    }

    // Function to perform Topological Sort
    void topologicalSort(vector<vector<int>> &adj, int V)
    {
        stack<int> Stack; // Stack to store the result
        vector<bool> visited(V, false);

        // Call the recursive helper function to store
        // Topological Sort starting from all vertices one by
        // one
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                topologicalSortUtil(i, adj, visited, Stack);
        }

        // Print contents of stack
        while (!Stack.empty())
        {
            cout << Stack.top() << " ";
            Stack.pop();
        }
    }

    void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &result)
    {
        visited[node] = true;

        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                dfs(neighbor, adj, visited, result);
            }
        }

        result.push(node);
    }

    vector<int> topologicalSort(int numNodes, vector<vector<int>> &adj)
    {
        vector<bool> visited(numNodes, false);
        stack<int> result;

        for (int i = 0; i < numNodes; ++i)
        {
            if (!visited[i])
            {
                dfs(i, adj, visited, result);
            }
        }

        vector<int> sortedOrder;
        while (!result.empty())
        {
            sortedOrder.push_back(result.top());
            result.pop();
        }

        return sortedOrder;
    }
};

vector<int> TopSort(int v, vector<vector<int>> edges)
{
    vector<int> path;
    vector<vector<int>> adj(v);
    // build adj list
    for (auto i : edges)
    {
        adj[i[0]].push_back(i[1]);
    }

    vector<bool> visited(v);

    for (int i = 0; i < v; i++)
    {
    }

    return path;
}

int main()
{
    // Number of nodes
    int V = 4;
    // Edges
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {3, 1}, {3, 2}};

    // vector<int> sortedOrder = topologicalSort(V, edges);
    // for (auto x : sortedOrder)
    // {
    //     cout << x << endl;
    // }

    // // Graph represented as an adjacency list
    // vector<vector<int>> adj(V);

    // for (auto i : edges)
    // {
    //     adj[i[0]].push_back(i[1]);
    // }

    // cout << "Topological sorting of the graph: ";
    // topologicalSort(adj, V);
    return 0;
}