//����ָoffer��15.��ת����
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
��Ŀ������һ��������ת��������������ı�ͷ��
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
˼·��ʹ������ָ�룬�ֱ�ָ��ǰ�������Ľ�㡢����ǰһ������Լ���һ����㡣�ڱ�����ʱ������ǰ����β����ǰһ�������滻��
*/

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {}
};

ListNode* ReverseList(ListNode* pHead) {
	ListNode* pNode = pHead;
	ListNode* pPrev = NULL;
	ListNode* pReverse = NULL;
	while (pNode != NULL) {
		ListNode* pNext = pNode->next;
		if (pNext == NULL) {
			pReverse = pNode;
		}
		pNode->next = pPrev;
		pPrev = pNode;
		pNode = pNext;
	}
	return pReverse;
}

int main() {

}