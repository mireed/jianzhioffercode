//����ָoffer��62.�����������ĵ�k�����
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
��Ŀ����һ�ö��������������ҳ����еĵ�kС�Ľ�㡣���磬 ��5��3��7��2��4��6��8��    �У��������ֵ��С˳�����С����ֵΪ4��
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
˼·��������������һ���ص㣺���ӽ���ֵ < ������ֵ < ���ӽ���ֵ��
     ֻ��Ҫ���������һ�ö������������ͺ������ҳ����ĵ�k���㡣
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