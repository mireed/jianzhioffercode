//����ָoffer��34.��һ��ֻ����һ�ε��ַ�
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
��Ŀ����һ���ַ���(0<=�ַ�������<=10000��ȫ������ĸ���)���ҵ���һ��ֻ����һ�ε��ַ�,
     ����������λ��, ���û���򷵻� -1����Ҫ���ִ�Сд��.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
˼·������һ����ϣ����һ��ɨ���ʱ��ͳ��ÿ���ַ��ĳ��ִ������ڶ���ɨ���ʱ��������ַ����ֵĴ���Ϊ1���򷵻�����ַ���λ�á�
*/

#include <iostream>
#include <unordered_map>

using namespace std;

int FirstNotRepeatingChar(string str) {
	if (str.length() == 0) {
		return -1;
	}
	unordered_map<char, int> m;
	for (int i = 0; i < str.length(); i++) {
		m[str[i]]++;
	}
	for (int i = 0; i < str.length(); i++) {
		if (m[str[i]] == 1) {
			return i;
		}
	}
	return -1;
}