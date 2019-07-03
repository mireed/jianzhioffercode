//����ָoffer��25.��������ĸ���
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
��Ŀ������һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ����һ���ڵ㣬��һ������ָ��ָ������һ���ڵ㣩�����ؽ��Ϊ���ƺ�
     ���������head����ע�⣬���������벻Ҫ���ز����еĽڵ����ã�������������ֱ�ӷ��ؿգ�
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
˼·���󲿷��������뵽�Ŀ������ȸ��Ƹ���ָ���label��next��Ȼ���ٲ���random�����¡�����random�ַ�Ϊ���֣�һ����ÿ�ζ���ͷ���ң�
      ʱ�临�Ӷ�ΪO(n^2)����һ���ǿռ任ʱ�䣬����label��next��ͬʱ����һ��hash��������¾ɸ���ָ��Ķ�Ӧ��ϵ�����Ժ���ֻ��һ��
	  �����ҵ�random���㷨ʱ�临�Ӷ�ΪO(n)���������ｫ��������ĸ��ƹ��̷ֽ�Ϊ�������衣��д�����ʱ������ÿһ������һ��������
	  ����ÿ���������һ�����ܣ��������̵��߼�Ҳ�ͷǳ����������ˡ������������������
      ��һ�������Ƹ���ָ���label��next������������ǰѸ��ƵĽ�����Ԫ�����棬������ֱ�Ӵ����µ�����
      �ڶ��������ø��Ƴ����Ľ���random����Ϊ�¾ɽ����ǰ���Ӧ��ϵ������Ҳ��һ�������ҵ�random��
      ���������������������ԭ����ż���Ǹ��Ƶ�����
*/

#include <iostream>

using namespace std;

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {}
};

//���Ƹ���ָ���label��next
void CloneNodes(RandomListNode* pHead) {
	RandomListNode* pNode = pHead;
	while (pNode != NULL) {
		RandomListNode* pCloned = new RandomListNode(0);
		pCloned->label = pHead->label;
		pCloned->next = pHead->next;
		pCloned->random = NULL;

		pNode->next = pCloned;
		pNode = pCloned->next;
	}
}

//������ָ���random
void ConnectSiblingNodes(RandomListNode* pHead) {
	RandomListNode* pNode = pHead;
	while (pNode != NULL) {
		RandomListNode* pCloned = pNode->next;
		if (pNode->random != NULL) {
			pCloned->random = pNode->random->next;
		}
		pNode = pCloned->next;
	}
}

//��ָ���ָ��
RandomListNode* ReconnectNodes(RandomListNode* pHead) {
	RandomListNode* pNode = pHead;
	RandomListNode* pClonedHead = NULL;
	RandomListNode* pClonedNode = NULL;
	while (pNode != NULL) {
		pClonedHead = pClonedNode = pNode->next;
		pNode->next = pClonedNode->next;
		pNode = pNode->next;
	}
	while (pNode != NULL) {
		pClonedNode->next = pNode->next;
		pClonedNode = pClonedNode->next;
		pNode->next = pClonedNode->next;
		pNode = pNode->next;
	}
	return pClonedHead;
}

RandomListNode* Clone(RandomListNode* pHead)
{
	CloneNodes(pHead);
	ConnectSiblingNodes(pHead);
	return ReconnectNodes(pHead);
}