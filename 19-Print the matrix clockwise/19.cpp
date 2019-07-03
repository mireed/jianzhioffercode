//《剑指offer》19.顺时针打印矩阵
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
题目：输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
思路：将结果存入vector数组，从左到右，再从上到下，再从右到左，最后从下到上遍历。
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> printMatrix(vector<vector<int> > matrix) {
	int rows = matrix.size();
	int cols = matrix[0].size();
	vector<int> result;
	if (rows == 0 && cols == 0) {
		return result;
	}
	int left = 0, right = cols - 1, top = 0, bottom = rows - 1;
	while (left <= right && top <= bottom) {
		for (int i = left; i <= right; ++i) {
			result.push_back(matrix[top][i]);
		}
		for (int i = top + 1; i <= bottom; ++i) {
			result.push_back(matrix[i][right]);
		}
		if (top != bottom) {
			for (int i = right - 1; i >= left; --i) {
				result.push_back(matrix[bottom][i]);
			}
		}
		if (left != right) {
			for (int i = bottom - 1; i > top; --i) {
				result.push_back(matrix[i][left]);
			}
		}
		left++, right--, top++, bottom--;
	}
	return result;
}

int main() {

}