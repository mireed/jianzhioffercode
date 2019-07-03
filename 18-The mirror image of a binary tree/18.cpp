//����ָoffer��18.�������ľ���
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
��Ŀ�����������Ķ�����������任ΪԴ�������ľ���
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
˼·���������ڵ���������������������ӽڵ�Ľڵ�
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