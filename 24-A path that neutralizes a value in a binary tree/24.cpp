//����ָoffer��24.�������к�Ϊĳһֵ��·��
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
��Ŀ������һ�Ŷ�������һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����
     ·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
˼·��dfs�Լ�ǰ�������������������ջ���ֱ�����ʱ��������ս��
*/

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x):
		val(x), left(NULL), right(NULL){}
};

vector<int> temp;
vector<vector<int>> result;
vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
	if (root == NULL) {
		return result;
	}
	temp.push_back(root->val);
	if ((expectNumber - root->val) == 0 && root->left == NULL && root->right == NULL) {
		result.push_back(temp);
	}
	FindPath(root->left, expectNumber - root->val);
	FindPath(root->right, expectNumber - root->val);
	temp.pop_back();
	return result;
}