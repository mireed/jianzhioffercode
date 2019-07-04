//����ָoffer��57.����������һ�����
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
��Ŀ������һ�������������е�һ����㣬���ҳ��������˳�����һ����㲢�ҷ��ء�
     ע�⣬���еĽ�㲻�����������ӽ�㣬ͬʱ����ָ�򸸽���ָ�롣
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
˼·�����һ�����������������ô������һ�������������������������ӽ�㡣
     Ҳ����˵�����ӽ�����һֱ����ָ������������ָ�룬���Ǿ����ҵ�������һ����㡣
     �������Ƿ���һ�½��û�������������Ρ��������������������ӽ�㣬��ô������һ�����������ĸ���㡣
     ���һ������û�������������������Ǹ��������ӽ�㣬�������ξͱȽϸ��ӡ�
	 ���ǿ�������ָ�򸸽���ָ��һֱ���ϱ�����ֱ���ҵ�һ���������������ӽ��Ľ�㡣
	 ��������Ľ����ڣ���ô������ĸ�����������Ҫ�ҵ���һ����㡣
*/

#include <iostream>

using namespace std;

struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :
		val(x), left(NULL), right(NULL), next(NULL) {}
};

TreeLinkNode* GetNext(TreeLinkNode* pNode) {
	if (pNode == NULL) {
		return NULL;
	}
	TreeLinkNode* pNext = NULL;
	if (pNode->right != NULL) {
		TreeLinkNode* pRight = pNode->right;
		while (pRight->left != NULL) {
			pRight = pRight->left;
		}
		pNext = pRight;
	}
	else if (pNode->next != NULL) {
		TreeLinkNode* pCur = pNode;
		TreeLinkNode* pPar = pNode->next;
		while (pPar != NULL && pCur == pPar->right)
		{
			pCur = pPar;
			pPar = pCur->next;
		}
		pNext = pPar;
	}
	return pNext;
}
