#ifndef __common_h__
#define __common_h__
#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <queue>
#include <climits>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
using namespace std;
typedef pair<int, int> iPair;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

enum Color
{
    RED,
    BLACK
};

template <class T>
void printvector(vector<T> vec)
{
    cout << "[";
    for (size_t i = 0; i < vec.size(); i++)
    {
        cout << vec[i];
        if (i != vec.size() - 1)
            cout << ",";
    }
    cout << "]";
}

template <class S>
void printvector(vector<vector<S>> vecx)
{
    cout << "[";
    for (size_t i = 0; i < vecx.size(); i++)
    {
        printvector(vecx[i]);
        // if (i != vecx.size() - 1)
        //     cout << ",";
    }

    cout << "]\n";
}

#endif