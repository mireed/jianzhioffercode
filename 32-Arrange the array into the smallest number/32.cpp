//����ָoffer��32.�������ų���С����
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
��Ŀ������һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ����������������{3��32��321}��
      ���ӡ���������������ųɵ���С����Ϊ321323��
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
˼·����������⣬ȫ���е�Ȼ������������ʱ�临�Ӷ�ΪO(n!)�������������Լ�����һ�����򣬶�ƴ�Ӻ���ַ������бȽϡ�
      ����������£�
      ��ab > ba �� a ���� b��
      ��ab < ba �� a С�� b��
      ��ab = ba �� a ���� b��
      ������������������Ҫ�Ƚ�����ת�����ַ����ٽ��бȽϣ���Ϊ��Ҫ���������бȽϡ��Ƚ���֮�󣬰�˳��������ɡ�
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string PrintMinNumber(vector<int> numbers) {
	if (numbers.size() == 0) {
		return "";
	}
	sort(numbers.begin(), numbers.end(), cmp);
	string res;
	for (int i = 0; i < numbers.size(); i++) {
		res += numbers[i];
	}
	return res;
}

static bool cmp(int a, int b) {
	string A = to_string(a) + to_string(b);
	string B = to_string(b) + to_string(a);
	return A < B;
}