//����ָoffer��23.�����������ĺ����������
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
��Ŀ������һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ����
     ����������Yes���������No���������������������������ֶ�������ͬ
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
˼·���ݹ�
*/

#include <iostream>
#include <vector>

using namespace std;

bool VerifySquenceOfBST(vector<int> sequence) {
	return bst(sequence, 0, sequence.size() - 1);
}

bool bst(vector<int> seq, int begin, int end) {
	if (seq.empty() || begin > end) {
		return false;
	}
	int root = seq[end];
	int i = begin;
	for (; i < end; i++) {
		if (seq[i] > root) {
			break;
		}
	}
	for (int j = i; j < end; j++) {
		if (seq[j] < root) {
			return false;
		}
	}
	bool left = true;
	if (i > begin) {
		left = bst(seq, begin, i - 1);
	}
	bool right = true;
	if (i < end - 1) {
		right = bst(seq, i, end - 1);
	}
	return left && right;
}