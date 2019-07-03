//����ָoffer��03.��β��ͷ��ӡ����
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
��Ŀ������һ������������ֵ��β��ͷ��˳�򷵻�һ��ArrayList��
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
˼·��ͨ������������£����ǲ�ϣ���޸�ԭ����Ľṹ������һ���������������Ǿ���ġ�����ȳ��������ǿ���ʹ��ջʵ������˳��ÿ����һ
     ������ʱ�򣬰Ѹý��ŵ�һ��ջ�С�������������������ٴ�ջ����ʼ����������ֵ����һ���µ�����ṹ�����������ʵ���˷�ת
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {}
};

vector<int> printListFromTailToHead(ListNode* head) {
	stack<int> nodes;
	vector<int> result;
	ListNode *node = head;
	while (node != NULL) {
		nodes.push(node->val);
		node = node->next;
	}
	while (!nodes.empty()) {
		result.push_back(nodes.top());
		nodes.pop();
	}
	return result;
}

int main() {

}