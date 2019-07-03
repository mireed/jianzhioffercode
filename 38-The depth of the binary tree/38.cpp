//����ָoffer��38.�����������
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
��Ŀ������һ�ö����������������ȡ��Ӹ���㵽Ҷ������ξ����Ľ�㣨������Ҷ��㣩�γ�����һ��·�����·���ĳ���Ϊ������ȡ�
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
˼·�������������ȡ������ǵݹ�ķ���������DFS���������������:�ݹ����������������ȣ���ȡ���
      ��һ�ַ����ǰ��ղ�α���������BFS���������������:�����������У���ͬһ��εĽڵ�һ����ӣ������whileѭ��ͳ�Ʋ������
*/

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {}
};

//DFS
int TreeDepth(TreeNode* pRoot) {
	if (pRoot == NULL) {
		return 0;
	}
	int left = TreeDepth(pRoot->left);
	int right = TreeDepth(pRoot->right);
	return (left > right) ? (left + 1) : (right + 1);
}

//BFS
int TreeDepth(TreeNode* pRoot) {
	if (pRoot == NULL) {
		return 0;
	}
	queue<TreeNode*> que;
	int depth = 0;
	que.push(pRoot);
	while (!que.empty()) {
		int size = que.size();
		depth++;//forѭ������BFS˼�� ��ͬһ��Ľڵ����һ��forѭ���ѭ����++depth
		for (int i = 0; i < size; i++) {
			TreeNode* node = que.front();
			que.pop();
			if (node->left) {
				que.push(node->left);
			}
			if (node->right) {
				que.push(node->right);
			}
		}
	}
	return depth;
}
