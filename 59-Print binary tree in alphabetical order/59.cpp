//《剑指offer》59.按之字顺序打印二叉树
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
题目：请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，
      第三行按照从左到右的顺序打印，其他行以此类推。
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
思路：为了达到这样打印的效果，我们需要使用两个栈。我们在打印某一行结点时，把下一层的子结点保存到相应的栈里。
      如果当前打印的是奇数层（第一层、第三层等），则先保存左子树结点再保存右子树结点到第一个栈里。
      如果当前打印的是偶数层（第二层、第四层等），则则先保存右子树结点再保存左子树结点到第二个栈里。
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {}
};

stack<TreeNode*> s1, s2;
vector<vector<int> > Print(TreeNode* pRoot) {
	vector <vector<int> > result;
	if (pRoot == NULL) {
		return result;
	}
	s1.push(pRoot);
	while (!s1.empty() || !s2.empty()) {
		vector<int> temp;
		//偶数行
		while (!s1.empty()) {
			TreeNode* node = s1.top();
			temp.push_back(node->val);
			if (node->left != NULL) {
				s2.push(node->left);
			}
			if (node->right != NULL) {
				s2.push(node->right);
			}
			s1.pop();
		}
		if (!temp.empty()) {
			result.push_back(temp);
		}
		temp.clear();
		//奇数行
		while (!s2.empty()) {
			TreeNode* node = s2.top();
			temp.push_back(node->val);
			if (node->right != NULL) {
				s1.push(node->right);
			}
			if (node->left != NULL) {
				s1.push(node->left);
			}
			s2.pop();
		}
		if (!temp.empty()) {
			result.push_back(temp);
		}
	}
	return result;
}