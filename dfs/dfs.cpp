#include "../common.h"

void dfs(int node, vector<vector<int>>* graph, vector<bool>* visited) {
    // check whether node has been visited before
    if ((*visited)[node])
        return;
    // set as visited to avoid visiting the same node twice
    (*visited)[node] = true;
    // perform some action here
    cout << node;
    // traverse to the adjacent nodes in depth-first manner
    for (int i = 0; i < (*graph)[node].size(); ++i)
        dfs((*graph)[node][i], graph, visited);
}

int main()
{

    return 0;
}
