//����ָoffer��60.�Ѷ�������ӡ�ɶ���
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
��Ŀ�����ϵ��°����ӡ��������ͬһ����������������ÿһ�����һ�С�
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
˼·����������һ���⡶��ָOffer����ʮ�ţ�����֮��˳���ӡ����������һЩ��ţ��������������Ӧ���ǷŴ�˳���ˡ�
     ˼·����һ����һ�����������ڣ�����������ȳ���ʹ�ö��м���
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
		//ż����
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
		//������
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
