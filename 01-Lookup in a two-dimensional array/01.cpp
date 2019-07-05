//《剑指offer》01.二维数组中的查找
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
      请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
思路：首先选取数组中右上角的数字。如果该数字等于要查找的数字，查找过程结束；如果该数字大于要查找的数组，剔除这个数字所在的列；
     如果该数字小于要查找的数字，剔除这个数字所在的行。也就是说如果要查找的数字不在数组的右上角，则每一次都在数组的查找范围中
	 剔除一行或者一列，这样每一步都可以缩小查找的范围，直到找到要查找的数字，或者查找范围为空。

ps:不定长的二维数组的标准输入输出用do...while....
*/

#include <iostream>
#include <vector>

using namespace std;

bool find(int target, vector<vector<int>> array) {
	int m = array.size();
	int n = array[0].size();
	if (!array.empty() && m > 0 && n > 0) {
		int row = 0;
		int col = n - 1;
		while (row < m && col >= 0) {
			if (array[row][col] == target) {
				return true;
			}
			else if (array[row][col] > target) {
				col--;
			}
			else {
				row++;
			}
		}
		return false;
	}
}

int main() {
	int target, temp;
	cout << "请输入要找的目标数：" << endl;
	cin >> target;
	vector<vector<int>> test;
	vector<int> v;
	bool flag = true;
	cout << "请输入一个二维数组：" << endl;
	while (flag) {
		do {
			cin >> temp;
			if (!cin) {//当输入类型错误时从这里进入，也即输入完成
				flag = false;
				break;
			}
			v.push_back(temp);
		} while (cin.get() != '\n');
		if (flag) {
			test.push_back(v);
			v.clear();
		}
	}
	bool res = find(target, test);
	cout << res << endl;
	system("pause");
	return 0;
}