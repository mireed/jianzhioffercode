//《剑指offer》55.链表中环的入口结点
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
题目：给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
思路：如何判断一个链表是否存在环？设定两个指针slow，fast，均从头指针开始，每次分别前进1步、2步。
     如存在环，则两者相遇；如不存在环，fast遇到NULL退出。
    如果链表存在环，如果找到环的入口点？当fast若与slow相遇时，slow肯定没有走遍历完链表或者恰好遍历一圈。
	于是我们从链表头与相遇点分别设一个指针，每次各走一步，两个指针必定相遇，且相遇第一点为环入口点。
*/

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {}
};

ListNode* EntryNodeOfLoop(ListNode* pHead)
{
	if (pHead == NULL) {
		return NULL;
	}
	ListNode* meetingnode = MeetingNode(pHead);
	if (meetingnode == NULL) {
		return NULL;
	}
	// 回环链表结点个数
	int nodesloop = 1;
	// 找到环中结点个数
	ListNode* pNode1 = meetingnode;
	while (pNode1->next != meetingnode) {
		pNode1 = pNode1->next;
		nodesloop++;
	}
	pNode1 = pHead;
	// 第一个指针向前移动nodesloop步
	for (int i = 0; i < nodesloop; i++) {
		pNode1 = pNode1->next;
	}
	// 两个指针同时移动，找到环入口
	ListNode* pNode2 = pHead;
	while (pNode1 != pNode2) {
		pNode1 = pNode1->next;
		pNode2 = pNode2->next;
	}
	return pNode1;
}

ListNode* MeetingNode(ListNode* pHead) {
	ListNode* pSlow = pHead->next;
	if (pSlow == NULL) {
		return NULL;
	}
	ListNode* pFast = pSlow->next;
	while (pFast != NULL && pSlow != NULL) {
		if (pFast == pSlow) {
			return pFast;
		}
		pSlow = pSlow->next;
		pFast = pFast->next;
		if (pFast != NULL) {
			pFast = pFast->next;
		}
	}
	return NULL;
}