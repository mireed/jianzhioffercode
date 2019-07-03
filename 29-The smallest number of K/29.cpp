//《剑指offer》29.最小的K个数
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
题目：输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4。
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
思路：排序后暴力搜索或者堆排序
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> result;
//法1，暴力搜索
vector<int> GetLeastNumbers_Solution1(vector<int> input, int k) {
	if (input.size() == NULL || k > input.size()) {
		return result;
	}
	sort(input.begin(), input.end());
	for (int i = 0; i < k; i++) {
		result.push_back(input[i]);
	}
	return result;
}

//法2，堆排序
vector<int> GetLeastNumbers_Solution2(vector<int> input, int k) {
	int length = input.size();
	bool change = true;
	if (length <= 0 || k <= 0 || k > length) {
		return result;
	}
	for (int i = 0; i < length; i++) {
		if (result.size() < k) {
			result.push_back(input[i]);
		}
		else{
			if (change == true) {
				//1.构建大顶堆
				for (int j = k / 2; j >= 0; j--) {//从第一个非叶子节点从下至上从左至右调整结构
					HeadAdjust(result, j, k);
				}
				for (int j = k - 1; j > 0; j--) {//2.调整堆结构+交换堆顶元素与末尾元素
					swap(result[0], result[j]); //将堆顶元素与末尾元素进行交换
					HeadAdjust(result, 0, j);//重新对堆进行调整
				}
				change = false;
			}
			if (result[k - 1] > input[i]) {
				result[k - 1] = input[i];
				change = true;
			}
		}
	}
	return result;
}


void HeadAdjust(vector<int> &input, int parent, int length) {// 调整大顶堆（仅是调整过程，建立在大顶堆已构建的基础上）
	int temp = input[parent]; //先取出当前元素i
	int child = 2 * parent + 1;//从i结点的左子结点开始，也就是2i+1处开始
	while (child < length) {
		if (child + 1 < length && input[child] < input[child + 1]) {//如果左子结点小于右子结点，k指向右子结点
			child++;
		}
		if (temp >= input[child]) {//如果子节点大于父节点，将子节点值赋给父节点（不用进行交换）
			break;
		}
		input[parent] = input[child];

		parent = child;
		child = 2 * parent + 1;
	}
	input[parent] = temp;//将temp值放到最终的位置
}