//����ָoffer��14.�����е�����k�����
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
��Ŀ������һ����������������е�����k����㡣
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
˼·�����ǿ��Զ�������ָ�롣��һ��ָ��������ͷָ�뿪ʼ������ǰ��k-1���ڶ���ָ�뱣�ֲ������ӵ�k����ʼ���ڶ���ָ��Ҳ��ʼ�������ͷ
     ָ�뿪ʼ��������������ָ��ľ��뱣����k-1������һ��������ǰ��ģ�ָ�뵽�������β���ʱ���ڶ���ָ�루���ں���ģ�ָ�������ǵ�����k
     ����㡣
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