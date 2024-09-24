#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

//https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
//TODO: Write the algo
/*
	Serialize Steps:
	1. Go through the Tree Level by Level
	2. Construct a LEVEL based vector size
	3. Push the entire Vector to a the result vector.
*/
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
};

class Solution {
private:
	int getTreeHeight(TreeNode* root) {
		if (root == nullptr)
			return 0;
		int left = getTreeHeight(root->left);
		int right = getTreeHeight(root->right);
		return max(left, right) + 1;

	}
	
	//FULL Tree
	vector< vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> levels;
		int treeLevels = getTreeHeight(root);

		for (int i = 0; i < treeLevels; i++) {
			vector<int> newVec(pow(2, i));
			levels.push_back(newVec);
		}

		if (root == nullptr) {
			return levels;
		}

		levels[0].at(0) = root->val;

		queue<TreeNode*> Q;
		Q.push(root);

		int levelIndex = 1;

		while (!Q.empty()) {
			if (levelIndex >= levels.size())
				break;

			int levelCellIndex = 0;
			for (int i = 0; i < levelIndex; i++) {
				TreeNode* node = Q.front();

				if (node->left) {
					levels[levelIndex].at(levelCellIndex) = node->left->val;
					Q.push(node->left);
					levelCellIndex++;
				}
				else {
					levels[levelIndex].at(levelCellIndex) = INT_MAX;
					levelCellIndex++;
				}

				if (node->right) {
					levels[levelIndex].at(levelCellIndex) = node->right->val;
					Q.push(node->right);
					levelCellIndex++;
				}
				else {
					levels[levelIndex].at(levelCellIndex) = INT_MAX;
					levelCellIndex++;
				}
				Q.pop();
			}
			levelIndex++;
		}

		return levels;
	}

	vector<string> splitter(string strInput) {
		vector<string> vecResult;
		std::string delimiter = ",";
		size_t pos = 0;
		std::string token;
		while ((pos = strInput.find(delimiter)) != std::string::npos) {
			token = strInput.substr(0, pos);
			vecResult.push_back(token);
			strInput.erase(0, pos + delimiter.length());
		}
		return vecResult;
	}
public:
	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		vector< vector<int>> levels = levelOrder(root);
		string strResult = "[";
		for (auto vec : levels) {
			for (auto elem : vec) {
				if (elem == INT_MAX) {
					strResult += "null,";
				}
				else
				{
					strResult += to_string(elem) + ",";
				}
			}
		}
		strResult = strResult.substr(0, strResult.length() - 1);
		strResult += "]";
		return strResult;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		vector<string> nodes = splitter(data);
		int levels = sqrt(nodes.size() + 1);

		TreeNode* root = nullptr;
		return root;
	}
};


/* utility that allocates a new node with the
given data and NULL left and right pointers. */
TreeNode* newnode(int data)
{
	TreeNode* Node = new TreeNode();
	Node->val = data;
	Node->left = NULL;
	Node->right = NULL;
	
	return(Node);
}

TreeNode* BuildTreeHelper(vector<int> nodes, int start, int end);

TreeNode* BuildTree(vector<int> nodes) {
	if (nodes.size() == 0)
		return nullptr;

	TreeNode* root = newnode(nodes[0]);
	int middlePoint = (nodes.size()-1)/2;
	root->left = BuildTreeHelper(nodes, 1, middlePoint);
	root->right = BuildTreeHelper(nodes, middlePoint+1, nodes.size()-1);
	return root;
}

TreeNode* BuildTreeHelper(vector<int> nodes, int start, int end) {
	if (start > end)
		return nullptr;

	if (start == end)
	{
		TreeNode* root = newnode(nodes[start]);
		return root;
	}
	else {
		int middlePoint = (end - start) / 2;
		TreeNode* root = newnode(nodes[start]);
		root->left = BuildTreeHelper(nodes, start + 1, middlePoint);
		root->right = BuildTreeHelper(nodes, middlePoint + 1, end);
		return root;
	}
}

int main()
{
	/*

	TreeNode* root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);
	root->right->right = newnode(5);
	root->right->left = newnode(4);
		Solution s;
		string strInput = "1,2,3,null,null,4,5,";
		cout << s.deserialize(strInput) << endl;
	*/


	vector<int> nums{ 10,20,30,40,50,60,70 };
	TreeNode* root = BuildTree(nums);




	cout << endl;
}
