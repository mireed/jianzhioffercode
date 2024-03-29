//《剑指offer》16.合并两个排序的链表
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
题目：输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
思路：先判断输入的链表是否为空的指针。如果第一个链表为空，则直接返回第二个链表；如果第二个链表为空，则直接返回第一个链表。如果两个链表
     都是空链表，合并的结果是得到一个空链表。
     两个链表都是排序好的，我们只需要从头遍历链表，判断当前指针，哪个链表中的值小，即赋给合并链表指针即可。使用递归就可以轻松实现。
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