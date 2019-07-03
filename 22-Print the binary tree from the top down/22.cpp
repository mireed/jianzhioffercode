//《剑指offer》22.从上往下打印二叉树
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
题目：从上往下打印出二叉树的每个节点，同层节点从左至右打印。
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
思路：每一次打印一个结点的时候，如果该结点有子结点，则把该结点的子结点放到一个队列的末尾。
      接下来到队列的头部取出最早进入队列的结点，重复前面的打印操作，直至队列中所有的结点都打印出来为止。
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL){}
};

queue<TreeNode*> que;
vector<int> result;
vector<int> PrintFromTopToBottom(TreeNode* root) {
	if (root == NULL) {
		return result;
	}
	que.push(root);
	TreeNode* fr;
	while (!que.empty()) {
		fr = que.front();
		result.push_back(fr->val);
		if (fr->left != NULL) {
			que.push(fr->left);
		}
		if (fr->right != NULL) {
			que.push(fr->right);
		}
		que.pop();
	}
	return result;
}