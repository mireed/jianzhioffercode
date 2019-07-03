//《剑指offer》38.二叉树的深度
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
题目：输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
思路：求二叉树的深度。可以是递归的方法，属于DFS（深度优先搜索）:递归算出左右子树的深度，再取最大；
      另一种方法是按照层次遍历，属于BFS（广度优先搜索）:借助辅助队列，将同一层次的节点一起入队，在外的while循环统计层次数。
*/

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {}
};

//DFS
int TreeDepth(TreeNode* pRoot) {
	if (pRoot == NULL) {
		return 0;
	}
	int left = TreeDepth(pRoot->left);
	int right = TreeDepth(pRoot->right);
	return (left > right) ? (left + 1) : (right + 1);
}

//BFS
int TreeDepth(TreeNode* pRoot) {
	if (pRoot == NULL) {
		return 0;
	}
	queue<TreeNode*> que;
	int depth = 0;
	que.push(pRoot);
	while (!que.empty()) {
		int size = que.size();
		depth++;//for循环体现BFS思想 把同一层的节点放在一个for循环里，循环外++depth
		for (int i = 0; i < size; i++) {
			TreeNode* node = que.front();
			que.pop();
			if (node->left) {
				que.push(node->left);
			}
			if (node->right) {
				que.push(node->right);
			}
		}
	}
	return depth;
}
