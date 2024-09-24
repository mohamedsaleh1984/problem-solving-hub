#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
};

class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		vector<vector<int>> res = { {} };
		vector<int> entry = {};
		//entry.push_back(root->val);
		pathSumFiller(root, targetSum, entry, res);
		return res;
	}

	void pathSumFiller(TreeNode* root, int targetSum, vector<int>& entry, vector<vector<int>>& res) {
		if (root == NULL)
			return;
		targetSum = targetSum - root->val;
		
		if (root->left == NULL && root->right == NULL && targetSum == 0) {
			res.push_back(entry);
		}
		else {
			entry.push_back(root->val);
			pathSumFiller(root->left, targetSum, entry, res);
			pathSumFiller(root->right, targetSum, entry, res);

		}
			
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
	struct TreeNode* t1 = newNode(5);
	t1->left = newNode(4);
	t1->left->left = newNode(11);
	t1->left->left->left = newNode(7);
	t1->left->left->right = newNode(2);

	t1->right = newNode(8);
	t1->right->left = newNode(13);
	t1->right->right = newNode(4);
	t1->right->right->right = newNode(1);
	t1->right->right->left = newNode(5);


	/*struct TreeNode* t2 = newNode(1);
	t2->left = newNode(2);
	 */

	 /*struct TreeNode* t3 = newNode(1);
	 t3->left = newNode(2);
	 t3->right = newNode(3);*/

	//struct TreeNode* t4 = newNode(1);
	//t4->left = newNode(2);

	Solution s;
	vector<vector<int>> result = s.pathSum(t1, 22);

	return 0;
}
