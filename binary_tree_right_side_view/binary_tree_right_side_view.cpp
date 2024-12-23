#include "../common.h"
// https://leetcode.com/problems/binary-tree-right-side-view/
// 3ms Beats7.37%
// 12/02/2024
class Solution {
public:
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
