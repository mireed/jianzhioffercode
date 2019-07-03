//《剑指offer》18.二叉树的镜像
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
题目：操作给定的二叉树，将其变换为源二叉树的镜像。
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
思路：交换根节点的左右子树，交换左右子节点的节点
*/

#include <iostream>

using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL){}
};

void Mirror(TreeNode *pRoot) {
	if ((pRoot == NULL) || (pRoot->left == NULL && pRoot->right == NULL)) {
		return;
	}
	TreeNode* pTemp = pRoot->left;
	pRoot->left = pRoot->right;
	pRoot->right = pTemp;
	if (pRoot->left) {
		Mirror(pRoot->left);
	}
	if (pRoot->right) {
		Mirror(pRoot->right);
	}
}

int main() {

}