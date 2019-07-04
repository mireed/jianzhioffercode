//《剑指offer》62.二叉搜索树的第k个结点
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
题目：定一棵二叉搜索树，请找出其中的第k小的结点。例如， （5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4。
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
思路：二叉搜索树的一个特点：左子结点的值 < 根结点的值 < 右子结点的值。
     只需要用中序遍历一棵二叉搜索树，就很容易找出它的第k大结点。
*/

#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {}
};

TreeNode* KthNode(TreeNode* pRoot, int k) {
	if (pRoot == NULL || k == 0) {
		return NULL;
	}
	return KthNodeCore(pRoot, k);
}
TreeNode* KthNodeCore(TreeNode* pRoot, int &k) {
	TreeNode* target = NULL;
	if (pRoot->left != NULL) {
		target = KthNodeCore(pRoot->left, k);
	}
	if (target == NULL) {
		if (k == 1) {
			target == pRoot;
		}
		k--;
	}
	if (pRoot->right != NULL && target == NULL) {
		target = KthNodeCore(pRoot->right, k);
	}
	return target;
}