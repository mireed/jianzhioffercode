//����ָoffer��13.��������˳��ʹ����λ��ż��ǰ��
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
��Ŀ������һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ�����е�����λ�������ǰ�벿�֣����е�ż��λ������ĺ�벿�֣�
     ����֤������������ż����ż��֮������λ�ò��䡣
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
˼·������˫����У��������飬����ǰ���룬ż������롣���ʹ��assign����ʵ�ֲ�ͬ���������ݵ����͸�ֵ��
*/

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void reOrderArray(vector<int> &array) {
	deque<int> result;
	int size = array.size();
	for (int i = 0; i < size; i++) {
		if (array[size - i - 1] % 2 == 1) {
			result.push_back(array[size - i - 1]);
		}
		if (array[i] % 2 == 0) {
			result.push_back(array[i]);
		}
	}
	array.assign(result.begin(), result.end());
}

int main() {
	 
}