//《剑指offer》24.二叉树中和为某一值的路径
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
题目：输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
     路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
思路：dfs以及前序遍历，借助两个辅助栈，分别存放临时结果和最终结果
*/

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x):
		val(x), left(NULL), right(NULL){}
};

vector<int> temp;
vector<vector<int>> result;
vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
	if (root == NULL) {
		return result;
	}
	temp.push_back(root->val);
	if ((expectNumber - root->val) == 0 && root->left == NULL && root->right == NULL) {
		result.push_back(temp);
	}
	FindPath(root->left, expectNumber - root->val);
	FindPath(root->right, expectNumber - root->val);
	temp.pop_back();
	return result;
}