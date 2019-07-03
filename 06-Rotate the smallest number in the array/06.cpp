//����ָoffer��06.��ת�������С����
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
��Ŀ����һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת�� ����һ���ǵݼ�����������һ����ת�������ת�������СԪ�ء� 
      ��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1�� NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
˼·�����ַ�������ָ��ֱ�ָ�������һ�������һ��Ԫ�أ�����С��Χ�����Ǳ߽����
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