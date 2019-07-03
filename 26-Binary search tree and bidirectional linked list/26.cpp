//����ָoffer��26.������������˫������
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
��Ŀ������һ�ö��������������ö���������ת����һ�������˫������Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
˼·�����ݶ������������ص㣺�����ֵ<������ֵ<�ҽ���ֵ�����ǲ��ѷ��֣�ʹ�ö�����������������������ݵ����򣬾��������˳��
     ��ˣ����ȣ�ȷ���˶����������ı��������������������ǿ���ͼ�����ǿ��԰����ֳ��������֣�ֵΪ10�Ľ�㡢�����Ϊ6���������������
	 Ϊ14������������������˫������Ķ��壬ֵΪ10�Ľ�㽫�����������������һ���������������ͬʱ����������������С�Ľ������������
	 �������������˳�򣬵����Ǳ����������ʱ�������������Ѿ�ת����һ������ĺõ�˫�������ˣ����Ҵ������������һ���Ľ���ǵ�ǰֵ��
	 ��Ľ�㡣���ǰ�ֵΪ8�Ľ��͸��������������10�ͳ������һ����㣬�������Ǿ�ȥ���������������Ѹ���������������С�Ľ������������
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

TreeNode* Convert(TreeNode* pRootOfTree) {
	TreeNode* pLastNodeinList = NULL;//��¼˫������β���
	ConvertNode(pRootOfTree, &pLastNodeinList);//��ʼת���ڵ�
	TreeNode* pHeadinList = pLastNodeinList;
	while (pHeadinList != NULL && pHeadinList->left != NULL)
	{
		pHeadinList = pHeadinList->left;
	}
	return pHeadinList;
}

void ConvertNode(TreeNode* pNode, TreeNode** pLastNodeInList) {
	if (pNode == NULL) {//Ҷ�ڵ�ֱ�ӷ���
		return;
	}
	TreeNode* pCur = pNode;
	if (pCur->left != NULL) {//�ݹ�������
		ConvertNode(pCur->left, pLastNodeInList);
	}
	pCur->left = *pLastNodeInList;//��ָ��
	if (*pLastNodeInList != NULL) {//��ָ��
		(*pLastNodeInList)->right = pCur;
	}
	*pLastNodeInList = pCur;
	if (pCur->right != NULL) {
		ConvertNode(pCur->right, pLastNodeInList);
	}
}