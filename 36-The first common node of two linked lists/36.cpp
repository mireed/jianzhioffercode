//《剑指offer》36.两个链表的第一个公共结点
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
题目：输入两个链表，找出它们的第一个公共结点。
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
思路：方法一：我们可以把两个链表拼接起来，一个pHead1在前pHead2在后，一个pHead2在前pHead1在后。这样，生成了两个相同长度的链表，
             那么我们只要同时遍历这两个表，就一定能找到公共结点。时间复杂度O(m+n)，空间复杂度O(m+n)。
     方法二：我们也可以先把长的链表的头砍掉，让两个链表长度相同，这样，同时遍历也能找到公共结点。此时，时间复杂度O(m+n)，
	         空间复杂度为O(MAX(m,n))。
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
