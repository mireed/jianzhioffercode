//����ָoffer��01.��ά�����еĲ���
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
��Ŀ����һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
      �����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
˼·������ѡȡ���������Ͻǵ����֡���������ֵ���Ҫ���ҵ����֣����ҹ��̽�������������ִ���Ҫ���ҵ����飬�޳�����������ڵ��У�
     ���������С��Ҫ���ҵ����֣��޳�����������ڵ��С�Ҳ����˵���Ҫ���ҵ����ֲ�����������Ͻǣ���ÿһ�ζ�������Ĳ��ҷ�Χ��
	 �޳�һ�л���һ�У�����ÿһ����������С���ҵķ�Χ��ֱ���ҵ�Ҫ���ҵ����֣����߲��ҷ�ΧΪ�ա�

ps:�������Ķ�ά����ı�׼���������do...while....
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
	cout << "������Ҫ�ҵ�Ŀ������" << endl;
	cin >> target;
	vector<vector<int>> test;
	vector<int> v;
	bool flag = true;
	cout << "������һ����ά���飺" << endl;
	while (flag) {
		do {
			cin >> temp;
			if (!cin) {//���������ʹ���ʱ��������룬Ҳ���������
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