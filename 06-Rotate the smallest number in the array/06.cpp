//《剑指offer》06.旋转数组的最小数字
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。 
      例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
思路：二分法，两个指针分别指向数组第一个和最后一个元素，逐渐缩小范围，考虑边界调节
*/

#include <iostream>
#include <vector>

using namespace std;

int minNumberInRotateArray(vector<int> rotateArray) {
	int size = rotateArray.size();
	if (size == 0) {
		return 0;
	}
	int left = 0;
	int right = size - 1;
	int mid = 0;
	while (rotateArray[left] >= rotateArray[right]) {
		if (right - left == 1) {
			mid = right;
			break;
		}
		mid = left + (right - left) / 2;
		if (rotateArray[left] == rotateArray[right] && rotateArray[mid] == rotateArray[right]) {
			return MininOrder(rotateArray, left, right);
		}
		if (rotateArray[mid] >= rotateArray[left]) {
			left = mid;
		}
		else {
			right = mid;
		}
	}
	return rotateArray[mid];
}

int MininOrder(vector<int>& num, int left, int right) {
	int result = num[left];
	for (int i = left + 1; i < right; ++i) {
		if (num[i] < result) {
			result = num[i];
		}
	}
	return result;
}

int main() {

}