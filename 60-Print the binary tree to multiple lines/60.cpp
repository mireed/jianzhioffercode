//《剑指offer》60.把二叉树打印成多行
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
题目：从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
思路：这道题比上一道题《剑指Offer（五十九）：按之字顺序打印二叉树》简单一些，牛客网将这两道题应该是放错顺序了。
     思路和上一道题一样，区别在于，这把是先入先出，使用队列即可
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {}
};

queue<TreeNode*> q1, q2;
vector<vector<int> > Print(TreeNode* pRoot) {
	vector <vector<int> > result;
	if (pRoot == NULL) {
		return result;
	}
	q1.push(pRoot);
	while (!q1.empty() || !q2.empty()) {
		vector<int> temp;
		//偶数行
		while (!q1.empty()) {
			TreeNode* node = q1.front();
			temp.push_back(node->val);
			if (node->left != NULL) {
				q2.push(node->left);
			}
			if (node->right != NULL) {
				q2.push(node->right);
			}
			q1.pop();
		}
		if (!temp.empty()) {
			result.push_back(temp);
		}
		temp.clear();
		//奇数行
		while (!q2.empty()) {
			TreeNode* node = q2.front();
			temp.push_back(node->val);
			if (node->left != NULL) {
				q1.push(node->left);
			}
			if (node->right != NULL) {
				q1.push(node->right);
			}
			q2.pop();
		}
		if (!temp.empty()) {
			result.push_back(temp);
		}
	}
	return result;
}
