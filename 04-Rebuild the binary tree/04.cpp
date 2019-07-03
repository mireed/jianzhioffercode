//����ָoffer��04.�ؽ�������
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
��Ŀ������ĳ��������ǰ���������������Ľ�������ؽ����ö����������������ǰ���������������Ľ���ж������ظ������֡�
      ��������ǰ���������{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}�����ؽ������������ء�
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
˼·�� ǰ��������ȷ��ʸ���㣬�ٷ������ӽ�㣬���������ӽ�㡣
       ����������ȷ������ӽ�㣬�ٷ��ʸ���㣬���������ӽ�㡣
       ǰ����������У���һ�������������ĸ�����ֵ����������������У�������ֵ�����е��м䣬�������Ľ���ֵλ��
       ������ֵ����ߣ����������Ľ���ֵλ�ڸ�����ֵ���ұߡ�ʣ�µ����ǿ��Եݹ���ʵ�֣�
*/

#include <iostream>
#include <vector>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
	if (pre.size() == 0) {
		return NULL;
	}
	vector<int> pre_left, pre_right, vin_left, vin_right;
	TreeNode *head = new TreeNode(pre[0]);
	int root = 0;
	for (int i = 0; i < pre.size(); ++i) {
		if (pre[0] == vin[i]) {
			root = i;
			break;
		}
	}
	for (int i = 0; i < root; i++) {
		vin_left.push_back(vin[i]);
		pre_left.push_back(pre[i + 1]);
	}
	for (int i = root + 1; i < pre.size(); i++) {
		vin_right.push_back(vin[i]);
		pre_right.push_back(pre[i]);
	}
	head->left = reConstructBinaryTree(pre_left, vin_left);
	head->right = reConstructBinaryTree(pre_left, vin_right);
	return head;
}

int main() {

}
