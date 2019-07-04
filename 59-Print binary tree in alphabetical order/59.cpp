//����ָoffer��59.��֮��˳���ӡ������
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
��Ŀ����ʵ��һ����������֮���δ�ӡ������������һ�а��մ����ҵ�˳���ӡ���ڶ��㰴�մ��������˳���ӡ��
      �����а��մ����ҵ�˳���ӡ���������Դ����ơ�
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
˼·��Ϊ�˴ﵽ������ӡ��Ч����������Ҫʹ������ջ�������ڴ�ӡĳһ�н��ʱ������һ����ӽ�㱣�浽��Ӧ��ջ�
      �����ǰ��ӡ���������㣨��һ�㡢������ȣ������ȱ�������������ٱ�����������㵽��һ��ջ�
      �����ǰ��ӡ����ż���㣨�ڶ��㡢���Ĳ�ȣ��������ȱ�������������ٱ�����������㵽�ڶ���ջ�
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
		//ż����
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
		//������
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