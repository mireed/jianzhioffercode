//����ָoffer��39.ƽ�������
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
��Ŀ������һ�ö��������жϸö������Ƿ���ƽ���������
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
˼·��ƽ��������Ķ����ǣ���ν��ƽ��֮�⣬������������һ��������������������ĸ߶Ȳ����1��
      ����˼·�����֣�ֻ����һ�εķ������š�
	  �ظ�������Σ�
      �ڱ�������ÿ������ʱ�򣬵��ú���TreeDepth�õ�����������������ȡ����ÿ���������������������������1��
      ������һ��ƽ��Ķ����������ַ�����ȱ���ǣ������жϸ�����ǲ���ƽ��ģ���Ҫʹ��TreeDepth���������������ȣ�
      Ȼ����Ҫ�����ж������ǲ���ƽ��ģ�������Ҫʹ��TreeDepth���������������������ȣ������͵����˴������ظ�������
      ֻ����һ�Σ�
      �ظ�������Ӱ���㷨�����ܣ����Ժ��б�Ҫ���ղ���Ҫ�ظ������ķ�������������ú�������ķ�ʽ������������ÿһ����㣬
      �ڱ�����һ�����֮ǰ���Ǿ��Ѿ���������������������ֻҪ�ڱ���ÿ������ʱ���¼������ȣ�ĳһ������ȵ�������Ҷ����·���ĳ��ȣ�
	  �����ǾͿ���һ�߱���һ���ж�ÿ������ǲ���ƽ��ġ�
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

//�ظ��������
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

//ֻ����һ��
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