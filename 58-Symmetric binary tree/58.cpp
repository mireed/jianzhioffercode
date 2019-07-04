//����ָoffer��58.�ԳƵĶ�����
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
��Ŀ����ʵ��һ�������������ж�һ�Ŷ������ǲ��ǶԳƵġ�ע�⣬���һ��������ͬ�˶������ľ�����ͬ���ģ�������Ϊ�ԳƵġ�
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
˼·������ͨ�������ֲ�ͬ�Ķ����������㷨����ǰ���������������ͺ���������������ֱ����㷨�У������ȱ������ӽ���ٱ������ӽ�㡣
      ��ǰ�����Ϊ�������ǿ��Զ���һ�������㷨���ȱ������ӽ���ٱ������ӽ�㣬���ҳ���Ϊǰ������ĶԳƱ���.��Ҫ���ǿսڵ�
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