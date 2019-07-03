//����ָoffer��36.��������ĵ�һ���������
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
��Ŀ���������������ҳ����ǵĵ�һ��������㡣
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
˼·������һ�����ǿ��԰���������ƴ��������һ��pHead1��ǰpHead2�ں�һ��pHead2��ǰpHead1�ں�������������������ͬ���ȵ�����
             ��ô����ֻҪͬʱ��������������һ�����ҵ�������㡣ʱ�临�Ӷ�O(m+n)���ռ临�Ӷ�O(m+n)��
     ������������Ҳ�����Ȱѳ��������ͷ��������������������ͬ��������ͬʱ����Ҳ���ҵ�������㡣��ʱ��ʱ�临�Ӷ�O(m+n)��
	         �ռ临�Ӷ�ΪO(MAX(m,n))��
*/

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {}
};

ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
	if (pHead1 == NULL || pHead2 == NULL) {
		return NULL;
	}
	unsigned int length1 = GetListLength(pHead1);
	unsigned int length2 = GetListLength(pHead2);
	ListNode* pHeadLong = pHead1;
	ListNode* pHeadShort = pHead2;
	int lengthdif = length1 - length2;
	if (length1 < length2) {
		ListNode* pHeadLong = pHead2;
		ListNode* pHeadShort = pHead1;
		int lengthdif = length2 - length1;
	}
	for (int i = 0; i < lengthdif; i++) {
		pHeadLong = pHeadLong->next;
	}
	while (pHeadLong != NULL && pHeadShort != NULL && pHeadLong != pHeadShort) {
		pHeadLong = pHeadLong->next;
		pHeadShort = pHeadShort->next;
	}
	return pHeadLong;
}

unsigned int GetListLength(ListNode* pHead) {
	if (pHead == NULL) {
		return 0;
	 }
	unsigned int length = 1;
	while (pHead->next != NULL) {
		pHead = pHead->next;
		length++;
	}
	return length;
}
