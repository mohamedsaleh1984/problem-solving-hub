#include <iostream>
#include <queue>
#include <malloc.h>
#include <stack>
using namespace std;


struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v) {
		val = v;
	}
};
//https://leetcode.com/problems/binary-tree-right-side-view/
class Solution {
private:
	int getTreeHeight(TreeNode* root) {
		if (root == nullptr)
			return 0;
		int left = getTreeHeight(root->left);
		int right = getTreeHeight(root->right);
		return max(left, right) + 1;
	}

	vector< vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> levels;
		int treeLevels = getTreeHeight(root);

		for (int i = 0; i < treeLevels; i++) {
			levels.push_back({});
		}

		if (root == nullptr) {
			return levels;
		}

		int iLevelIndex = 1;

		queue<TreeNode*> q;
		q.push(root);
		levels[0].push_back(root->val);

		while (iLevelIndex < levels.size()) {

			queue<TreeNode*> nodesInlevel;

			while (!q.empty()) {
				TreeNode* node = q.front();
				if (node->left)
					nodesInlevel.push(node->left);

				if (node->right)
					nodesInlevel.push(node->right);

				q.pop();
			}

			while (!nodesInlevel.empty())
			{
				TreeNode* node = nodesInlevel.front();
				q.push(node);
				levels[iLevelIndex].push_back(node->val);
				nodesInlevel.pop();
			}
			iLevelIndex++;
		}

		return levels;
	}
public:
	vector<int> rightSideView(TreeNode* root) {
		vector< vector<int>> nodesPerLevels = levelOrder(root);
		vector<int> result = {};
		for (int i = 0; i < nodesPerLevels.size(); i++) {
			result.push_back(nodesPerLevels[i].at(nodesPerLevels[i].size() - 1));
		}
		return result;
	}
};

struct TreeNode* newNode(int data)
{
	struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	node->val = data;
	node->left = NULL;
	node->right = NULL;
	return(node);
}

int main()
{
	struct TreeNode* root = newNode(3);
	root->left = newNode(9);
	root->right = newNode(20);
	root->right->left = newNode(15);
	root->right->right = newNode(7);
	printf("Level Order traversal of binary tree is \n");
	Solution s;
	vector<vector<int>> levels = s.levelOrder(root);
	for (auto vec : levels) {
		for (auto elem : vec)
		{
			cout << elem << " ";
		}
		cout << endl;
	}
	cout << endl;
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
