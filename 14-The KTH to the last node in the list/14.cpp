//《剑指offer》14.链表中倒数第k个结点
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
题目：输入一个链表，输出该链表中倒数第k个结点。
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
思路：我们可以定义两个指针。第一个指针从链表的头指针开始遍历向前走k-1，第二个指针保持不动；从第k步开始，第二个指针也开始从链表的头
     指针开始遍历。由于两个指针的距离保持在k-1，当第一个（走在前面的）指针到达链表的尾结点时，第二个指针（走在后面的）指针正好是倒数第k
     个结点。
*/

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {}
};

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	if (pListHead == NULL && k == 0) {
		return NULL;
	}
	ListNode* front = pListHead;
	ListNode* behind = pListHead;
	for (unsigned int i = 0; i < k - 1; i++) {
		if (front->next != NULL) {
			front = front->next;
		}
		else {
			return NULL;
		}
	}
	while (front->next != NULL) {
		front = front->next;
		behind = behind->next;
	}
	return behind;
}

int main() {

}