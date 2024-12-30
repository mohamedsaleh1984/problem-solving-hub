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
#include <set>
#include <chrono>
#include <thread>
#include <string>
#include  <bits/stdc++.h>
#include <chrono>
#include <functional>


using namespace std;
typedef pair<int, int> iPair;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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

void inorder(TreeNode* root){
    if(root == NULL)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void preorder(TreeNode* root){
    if(root == NULL)
        return;
    cout << root->val << " ";
    inorder(root->left);
    inorder(root->right);
}

void postorder(TreeNode* root){
if(root == NULL)
        return;
    inorder(root->left);
    inorder(root->right);
    cout << root->val << " ";
}


template <typename Func, typename... Args>
auto measureExecutionTime(Func&& func, Args&&... args) {
    auto start = std::chrono::high_resolution_clock::now();

    // void function
    if constexpr (std::is_void_v<std::invoke_result_t<Func, Args...>>) {
        // Handle void return type
        std::invoke(std::forward<Func>(func), std::forward<Args>(args)...);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        return duration.count(); // Only return the duration for void functions
    } else {
        // Handle non-void return type
        auto result = std::invoke(std::forward<Func>(func), std::forward<Args>(args)...);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        return std::make_pair(result, duration.count()); // Return result and duration
    }
}
#endif
