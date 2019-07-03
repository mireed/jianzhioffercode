//《剑指offer》23.二叉搜索树的后序遍历序列
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
题目：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
     如果是则输出Yes，否则输出No。假设输入的数组的任意两个数字都互不相同
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
思路：递归
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