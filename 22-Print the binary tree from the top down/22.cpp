//����ָoffer��22.�������´�ӡ������
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
��Ŀ���������´�ӡ����������ÿ���ڵ㣬ͬ��ڵ�������Ҵ�ӡ��
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
˼·��ÿһ�δ�ӡһ������ʱ������ý�����ӽ�㣬��Ѹý����ӽ��ŵ�һ�����е�ĩβ��
      �����������е�ͷ��ȡ�����������еĽ�㣬�ظ�ǰ��Ĵ�ӡ������ֱ�����������еĽ�㶼��ӡ����Ϊֹ��
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL){}
};

queue<TreeNode*> que;
vector<int> result;
vector<int> PrintFromTopToBottom(TreeNode* root) {
	if (root == NULL) {
		return result;
	}
	que.push(root);
	TreeNode* fr;
	while (!que.empty()) {
		fr = que.front();
		result.push_back(fr->val);
		if (fr->left != NULL) {
			que.push(fr->left);
		}
		if (fr->right != NULL) {
			que.push(fr->right);
		}
		que.pop();
	}
	return result;
}