//����ָoffer��17.�����ӽṹ
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
��Ŀ���������Ŷ�����A��B���ж�B�ǲ���A���ӽṹ����PS������Լ��������������һ�������ӽṹ����
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
˼·��Ҫ������A���Ƿ���ں���B�ṹһ�������������ǿ��Է�Ϊ��������һ������A���ҵ���B�ĸ���
      ���ֵһ���Ľ��R���ڶ������ж���A����RΪ���ڵ�������ǲ��ǰ�������Bһ���Ľṹ
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

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
	bool result = false;
	if (pRoot1 != NULL && pRoot2 != NULL) {
		if (pRoot1->val == pRoot2->val) {
			result = DoesTree1HasTree2(pRoot1, pRoot2);
		}
		if (!result) {
			result = HasSubtree(pRoot1->left, pRoot2);
		}
		if (!result) {
			result = HasSubtree(pRoot1->right, pRoot2);
		}
	}
	return result;
}

bool DoesTree1HasTree2(TreeNode* pRoot1, TreeNode* pRoot2) {
	if (pRoot1 == NULL) {
		return false;
	}
	if (pRoot2 == NULL) {
		return true;
	}
	if (pRoot1->val != pRoot2->val) {
		return false;
	}
	return DoesTree1HasTree2(pRoot1->right, pRoot2->right) && DoesTree1HasTree2(pRoot1->left, pRoot2->left);
}

int main() {

}