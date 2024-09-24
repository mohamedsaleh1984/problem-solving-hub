// Find Mode in Binary Search Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

//https://leetcode.com/problems/find-mode-in-binary-search-tree/
//TODO: Fix it
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

};

class Solution {
public:
	vector<int> findMode(TreeNode* root) {
		vector<int> list;
		vector<int> allNodes;
		traverse(root, allNodes);
		map<int, int> freqTable;
		for (int i = 0; i < allNodes.size(); i++) {
			freqTable[allNodes[i]]++;
		}

		map<int, int>::iterator it;
		int max = INT_MIN;
		int elem = 0;
		for (it = freqTable.begin(); it != freqTable.end(); it++)
		{
			if (it->second > max) {
				max = it->second;
				elem = it->first;
			}
		}
		list.push_back(elem);
		return list;
	}


	void traverse(TreeNode* root, vector<int>& nodes) {
		if (root == nullptr)
			return;

		traverse(root->left, nodes);
		nodes.push_back(root->val);
		traverse(root->right, nodes);
	}
};



int main()
{
	TreeNode* root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(2);

	Solution s;
	vector<int> vecResult = s.findMode(root);
	
	for (auto x : vecResult)
		cout << x << " ";

}
