//����ָoffer��19.˳ʱ���ӡ����
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
��Ŀ������һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ������
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
˼·�����������vector���飬�����ң��ٴ��ϵ��£��ٴ��ҵ��������µ��ϱ�����
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