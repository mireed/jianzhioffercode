//《剑指offer》35.第一个只出现一次的字符
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
题目：在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数P。
     并将P对1000000007取模的结果输出。 即输出P%1000000007。
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
思路：分治思想，采用归并排序的思路来处理
     这是一个归并排序的合并过程，主要是考虑合并两个有序序列时，计算逆序对数。
     对于两个升序序列，设置两个下标：两个有序序列的末尾。每次比较两个末尾值，如果前末尾大于后末尾值，则有”后序列当前长度“个逆序对；
	 否则不构成逆序对。然后把较大值拷贝到辅助数组的末尾，即最终要将两个有序序列合并到辅助数组并有序。
     这样，每次在合并前，先递归地处理左半段、右半段，则左、右半段有序，且左右半段的逆序对数可得到，再计算左右半段合并时逆序对的个数。
*/

#include <iostream>
#include <vector>

using namespace std;

int InversePairs(vector<int> data) {
	if (data.size() == 0) {
		return 0;
	}
	vector<int> copy;//排序的辅助数组
	for (int i = 0; i < data.size(); i++) {
		copy.push_back(data[i]);
	}
	return InversePairsCore(data, copy, 0, data.size() - 1) % 1000000007;
}

long InversePairsCore(vector<int> &data, vector<int> &copy, int begin, int end) {
	if (begin == end) {//如果指向中点，则没有逆序对
		copy[begin] = data[end];
		return 0;
	}
	int mid = (begin + end) >> 2;//求中点
	int leftcount = InversePairsCore(copy, data, begin, mid);//使data左半段有序，并返回左半段逆序对的数目
	int rightcount = InversePairsCore(copy, data, mid + 1, end);//使data右半段有序，并返回右半段逆序对的数目
	int i = mid; // i初始化为前半段最后一个数字的下标
	int j = end; // j初始化为后半段最后一个数字的下标
	int indexcopy = end; // 辅助数组复制的数组的最后一个数字的下标
	long count = 0; // 计数，逆序对的个数，注意类型
	while (i >= begin && j >= mid + 1) {
		if (data[i] > data[j]) {
			copy[indexcopy--] = data[i--];
			count += j - mid;
		}
		else {
			copy[indexcopy--] = data[j--];
		}
	}
	for (; i >= begin; --i) {
		copy[indexcopy--] = data[i];
	}
	for (; j >= mid + 1; --j) {
		copy[indexcopy--] = data[j];
	}
	return leftcount + rightcount + count;
}