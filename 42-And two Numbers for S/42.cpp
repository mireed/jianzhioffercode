//《剑指offer》42.和和为S的两个数字
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
题目：输入一个递增排序的数组和一个数字S，在数组中查找两个数，使的他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
思路：对于一个数组，我们可以定义两个指针，一个从左往右遍历（pleft），另一个从右往左遍历（pright）。
     首先，我们比较第一个数字和最后一个数字的和curSum与给定数字sum，如果curSum < sum，那么我们就要加大输入值，
     所以，pleft向右移动一位，重复之前的计算；如果curSum > sum，那么我们就要减小输入值，
     所以，pright向左移动一位，重复之前的计算；如果相等，那么这两个数字就是我们要找的数字，直接输出即可。
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> FindNumbersWithSum(vector<int> array, int sum) {
	vector<int> result;
	if (array.size() < 1) {
		return result;
	}
	int left = 0;
	int right = array.size() - 1;
	int curSum = array[left] + array[right];
	while (left < right) {
		if (curSum < sum) {
			left++;
		}
		else if (curSum > sum) {
			right--;
		}
		else {
			result.push_back[array[left]];
			result.push_back[array[right]];
			break;
		}
	}
	return result;
}

