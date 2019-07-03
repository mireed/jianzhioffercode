//《剑指offer》41.和为S的连续正数序列
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
题目：小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。但是他并不满足于此,
     他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。
     现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
思路：设定两个指针，一个指向第一个数，一个指向最后一个数，在此之前需要设定第一个数和最后一个数的值，由于是正数序列，
     所以可以把第一个数设为1，最后一个数为2（因为是要求是连续正数序列，最后不可能和第一个数重合）。
    下一步就是不断改变第一个数和最后一个数的值，如果从第一个数到最后一个数的和刚好是要求的和，那么把所有的数都添加到一个序列中；
    如果大于要求的和，则说明从第一个数到最后一个数之间的范围太大，因此减小范围，需要把第一个数的值加1，同时把当前和减去原来的第一个
	数的值；如果小于要求的和，说明范围太小，因此把最后一个数加1，同时把当前的和加上改变之后的最后一个数的值。
    这样，不断修改第一个数和最后一个数的值，就能确定所有连续正数序列的和等于S的序列了。
*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > FindContinuousSequence(int sum) {
	vector<vector<int> > result;
	int first = 1, second = 2;
	if (sum <= 0) {
		return result;
	}
	while (second > first) {
		int curSum = (first + second) * (second - first + 1) / 2;
		if (curSum < sum) {
			second++;
		}
		if (curSum == sum) {
			vector<int> temp;
			for (int i = first; i <= second; i++) {
				temp.push_back[i];
			}
			result.push_back[temp];
			first++;
		}
		if (curSum > sum) {
			first++;
		}
	}
	return result;
}