//����ָoffer��16.�ϲ��������������
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
��Ŀ�����������������������������������ϳɺ��������Ȼ������Ҫ�ϳɺ���������㵥����������
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
˼·�����ж�����������Ƿ�Ϊ�յ�ָ�롣�����һ������Ϊ�գ���ֱ�ӷ��صڶ�����������ڶ�������Ϊ�գ���ֱ�ӷ��ص�һ�����������������
     ���ǿ������ϲ��Ľ���ǵõ�һ��������
     ��������������õģ�����ֻ��Ҫ��ͷ���������жϵ�ǰָ�룬�ĸ������е�ֵС���������ϲ�����ָ�뼴�ɡ�ʹ�õݹ�Ϳ�������ʵ�֡�
*/

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {}
};

ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
	if (pHead1 == NULL) {
		return pHead2;
	}
	else if (pHead2 == NULL) {
		return pHead1;
	}
	ListNode* pMergeHead = NULL;
	if (pHead1->val < pHead2->val) {
		pMergeHead = pHead1;
		pMergeHead->next = Merge(pHead1->next, pHead2);
	}
	else {
		pMergeHead = pHead2;
		pMergeHead->next = Merge(pHead1, pHead2->next);
	}
	return pMergeHead;
}

int main() {

}