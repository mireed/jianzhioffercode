//《剑指offer》40.数组中只出现一次的数字
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
题目：一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
       要求时间复杂度是O(n)，空间复杂度是O(1)。
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
思路：顺序扫描法，但是这种方法的时间复杂度是O（n^2）。考虑用哈希表的方法，但是空间复杂度不是O（1）。
     异或的一个性质是：任何一个数字异或它自己都等于0
	 从头到尾一次异或数组中的每一个数字，那么最终得到的结果就是两个只出现一次的数组的异或结果。
	 因为其他数字都出现了两次，在异或中全部抵消了。由于两个数字肯定不一样，那么异或的结果肯定不为0，
	 也就是说这个结果数组的二进制表示至少有一个位为1。我们在结果数组中找到第一个为1的位的位置，记为第n位。
	 现在我们以第n位是不是1为标准把元数组中的数字分成两个子数组，第一个子数组中每个数字的第n位都是1，而第
	 二个子数组中每个数字的第n位都是0。
*/
#include <iostream>
#include <vector>

using namespace std;

void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
	if (data.size() < 2) {
		return;
	}
	int resultExclusiveOR = 0;
	for (int i = 0; i < data.size(); i++) {
		resultExclusiveOR ^= data[i];
	}
	unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);
	*num1 = *num2 = 0;
	for (int i = 0; i < data.size(); i++) {
		if (IsBit1(data[i], indexOf1)) {
			*num1 ^= data[i];
		 }
		else {
			*num2 ^= data[i];
		}
	}
}

unsigned int FindFirstBitIs1(int num) {//找到二进制数num第一个为1的位数，比如0010，第一个为1的位数是2
	unsigned int indexBit = 0;
	while ((num & 1) == 0 && (indexBit < 8 * sizeof(unsigned int))) {// 只判断一个字节的
		num = num >> 1;//向右移1位
		indexBit++;
	}
	return indexBit;
}

bool IsBit1(int num, unsigned int indexBit) {// 判断第indexBit位是否为1
	num = num >> indexBit;
	return (num & 1);
}