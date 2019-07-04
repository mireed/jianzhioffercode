//《剑指offer》58.对称的二叉树
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
题目：请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
思路：我们通常有三种不同的二叉树遍历算法，即前序遍历、中序遍历和后序遍历。在这三种遍历算法中，都是先遍历左子结点再遍历右子结点。
      以前序遍历为例，我们可以定义一个遍历算法，先遍历右子结点再遍历左子结点，暂且称其为前序遍历的对称遍历.且要考虑空节点
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

bool isSymmetrical(TreeNode* pRoot) {
	if (pRoot == NULL) {
		return true;
	}
	return isSymmetricalcur(pRoot, pRoot);
}

bool isSymmetricalcur(TreeNode* pRoot1, TreeNode* pRoot2) {
	if (pRoot1 == NULL && pRoot2 == NULL) {
		return true;
	}
	if (pRoot1 == NULL || pRoot2 != NULL) {
		return false;
	}
	if (pRoot1->val != pRoot2->val) {
		return false;
	}
	return isSymmetricalcur(pRoot1->left, pRoot2->right) && isSymmetricalcur(pRoot1->right, pRoot2->left);
}