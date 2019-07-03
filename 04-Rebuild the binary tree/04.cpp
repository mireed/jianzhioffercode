//《剑指offer》04.重建二叉树
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
      例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
思路： 前序遍历：先访问根结点，再访问左子结点，最后访问右子结点。
       中序遍历：先访问左子结点，再访问根结点，最后访问右子结点。
       前序遍历序列中，第一个数字总是树的根结点的值。在中序遍历序列中，根结点的值在序列的中间，左子树的结点的值位于
       根结点的值的左边，而右子树的结点的值位于根结点的值的右边。剩下的我们可以递归来实现；
*/

#include <iostream>
#include <vector>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
	if (pre.size() == 0) {
		return NULL;
	}
	vector<int> pre_left, pre_right, vin_left, vin_right;
	TreeNode *head = new TreeNode(pre[0]);
	int root = 0;
	for (int i = 0; i < pre.size(); ++i) {
		if (pre[0] == vin[i]) {
			root = i;
			break;
		}
	}
	for (int i = 0; i < root; i++) {
		vin_left.push_back(vin[i]);
		pre_left.push_back(pre[i + 1]);
	}
	for (int i = root + 1; i < pre.size(); i++) {
		vin_right.push_back(vin[i]);
		pre_right.push_back(pre[i]);
	}
	head->left = reConstructBinaryTree(pre_left, vin_left);
	head->right = reConstructBinaryTree(pre_left, vin_right);
	return head;
}

int main() {

}
