//《剑指offer》39.平衡二叉树
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
题目：输入一棵二叉树，判断该二叉树是否是平衡二叉树。
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
思路：平衡二叉树的定义是：所谓的平衡之意，就是树中任意一个结点下左右两个子树的高度差不超过1。
      解题思路有两种，只遍历一次的方法最优。
	  重复遍历多次：
      在遍历树的每个结点的时候，调用函数TreeDepth得到它的左右子树的深度。如果每个结点的左右子树的深度相差都不超过1，
      则这是一颗平衡的二叉树。这种方法的缺点是，首先判断根结点是不是平衡的，需要使用TreeDepth获得左右子树的深度，
      然后还需要继续判断子树是不是平衡的，还是需要使用TreeDepth获得子树的左右子树的深度，这样就导致了大量的重复遍历。
      只遍历一次：
      重复遍历会影响算法的性能，所以很有必要掌握不需要重复遍历的方法。如果我们用后序遍历的方式遍历二叉树的每一个结点，
      在遍历到一个结点之前我们就已经遍历了它的左右子树。只要在遍历每个结点的时候记录它的深度（某一结点的深度等于它到叶结点的路径的长度）
	  ，我们就可以一边遍历一边判断每个结点是不是平衡的。
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

//重复遍历多次
bool IsBalanced_Solution1(TreeNode* pRoot) {
	if (pRoot == NULL) {
		return true;
	}
	int left = TreeDepth(pRoot->left);
	int right = TreeDepth(pRoot->right);
	int depthdif = left - right;
	if (depthdif > 1 || depthdif < -1) {
		return false;
	}
	return IsBalanced_Solution1(pRoot->left) && IsBalanced_Solution1(pRoot->right);
}
int TreeDepth(TreeNode* pRoot) {
	if (pRoot == NULL) {
		return 0;
	}
	int left = TreeDepth(pRoot->left);
	int right = TreeDepth(pRoot->right);
	return (left > right) ? (left + 1) : (right + 1);
}

//只遍历一次
bool IsBalanced_Solution2(TreeNode* pRoot) {
	int depth = 0;
	return IsBalanced(pRoot, &depth);
}
int IsBalanced(TreeNode* pRoot, int* depth) {
	if (pRoot == NULL) {
		*depth = 0;
		return true;
	}
	int left, right;
	if (IsBalanced(pRoot->left, &left) && IsBalanced(pRoot->right, &right)) {
		int diff = left - right;
		if (diff <= 1 && diff >= -1) {
			*depth = 1 + (left > right ? left : right);
			return true;
		}
	}
	return false;
}