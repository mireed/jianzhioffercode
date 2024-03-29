﻿//《剑指offer》56.删除链表中重复的结点
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
题目：在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
     例如，链表1->2->3->3->4->4->5 处理后为 1->2->5。
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
思路：删除重复结点，只需要记录当前结点前的最晚访问过的不重复结点pPre、当前结点pCur、指向当前结点后面的结点pNext的三个指针即可。
     如果当前节点和它后面的几个结点数值相同，那么这些结点都要被剔除，然后更新pPre和pCur；如果不相同，则直接更新pPre和pCur。
需要考虑的是，如果第一个结点是重复结点我们该怎么办？这里我们分别处理一下就好，如果第一个结点是重复结点，那么就把头指针pHead也更新一下。
*/

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

ListNode* deleteDuplication(ListNode* pHead) {
	if (pHead == NULL) {
		return NULL;
	}
	// 指向当前结点前最晚访问过的不重复结点
	ListNode* pPre = NULL;
	// 指向当前处理的结点
	ListNode* pCur = pHead;
	// 指向当前结点后面的结点
	ListNode* pNext = NULL;
	while (pCur != NULL) {
		// 如果当前结点与下一个结点相同
		if (pCur->next != NULL && pCur->val == pCur->next->val) {
			pNext = pCur->next;
			// 找到不重复的最后一个结点位置
			while (pNext->next != NULL && pNext->next->val == pCur->val) {
				pNext = pNext->next;
			}
			// 如果pCur指向链表中第一个元素，pCur -> ... -> pNext ->... 
			// 要删除pCur到pNext, 将指向链表第一个元素的指针pHead指向pNext->next。
			if (pCur == pHead) {
				pHead = pNext->next;
			}
			// 如果pCur不指向链表中第一个元素，pPre -> pCur ->...->pNext ->... 
			// 要删除pCur到pNext，即pPre->next = pNext->next
			else {
				pPre->next = pNext->next;
			}
			// 向前移动
			pCur = pNext->next;
		}
		// 如果当前结点与下一个结点不相同
		else {
			pPre = pCur;
			pCur = pCur->next;
		}
	}
	return pHead;
}