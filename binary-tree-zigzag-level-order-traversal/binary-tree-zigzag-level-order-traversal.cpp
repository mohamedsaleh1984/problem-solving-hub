#include "../common.h"

// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal
// 0ms Beats100.00%
// 12/22/2024

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
				TreeNode*  node = q.front();
				if (node->left)
					nodesInlevel.push(node->left);

				if(node->right)
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector< vector<int>> levels = levelOrder(root);
        for(int i = 1 ; i < levels.size() ; i++){
            if(i %2 == 1){
                std::reverse(levels[i].begin(),levels[i].end()); 
            }
        }
        return levels;
    }
};


int main(int argc, char** argv){
    return 0;
}