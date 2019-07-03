//《剑指offer》37.数字在排序数组中出现的次数
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
题目：统计一个数字在排序数组中出现的次数。
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
思路：使用二分法找到数字在数组中出现的第一个位置，再利用二分法找到数字在数组中出现的第二个位置。时间复杂度为O(logn + logn)，
     最终的时间复杂度为O(logn)。
     举个例子，找到数字k在数组data中出现的次数。
     数组data中，数字k出现的第一个位置：我们对数组data进行二分，如果数组中间的数字小于k，说明k应该出现在中间位置的右边；
	 如果数组中间的数字大于k，说明k应该出现在中间位置的左边；如果数组中间的数字等于k，并且中间位置的前一个数字不等于k，
	 说明这个中间数字就是数字k出现的第一个位置。
     同理，数字k出现的最后一个位置，也是这样找的。但是判断少有不同。我们使用两个函数分别获得他们。
*/

#include <iostream>
#include <vector>

using namespace std;

int GetNumberOfK(vector<int> data, int k) {
	if (data.size() == NULL) {
		return 0;
	}
	int first = GetFirstK(data, k, 0, data.size() - 1);
	int last = GetLastK(data, k, 0, data.size() - 1);
	if (first != -1 && last != -1) {
		return last - first + 1;
	}
	return 0;
}

int GetFirstK(vector<int> data, int k, int begin, int end) {
	if (begin > end) {
		return -1;
	}
	int mid = (begin + end) >> 2;
	if (k == data[mid]) {
		if ((mid > 0 && data[mid - 1] != k) || mid == 0) {
			return mid;
		}
		else {
			end = mid - 1;
		}
	}
	else if (k > data[mid]) {
		begin = mid + 1;
	}
	else {
		end = mid - 1;
	}
	return GetFirstK(data, k, begin, end);
}

int GetLastK(vector<int> data, int k, int begin, int end) {
	if (begin > end) {
		return -1;
	}
	int mid = (begin + end) >> 2;
	if (k == data[mid]) {
		if (((mid + 1) < data.size() && data[mid + 1] != k) || mid == data.size() - 1) {
			return mid;
		}
		else {
			begin = mid + 1;
		}
	}
	else if (k > data[mid]) {
		begin = mid + 1;
	}
	else {
		end = mid + 1;
	}
	return GetLastK(data, k, begin, end);
}