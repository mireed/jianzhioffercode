//����ָoffer��27.�ַ���������
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
��Ŀ������һ���ַ���,���ֵ����ӡ�����ַ������ַ����������С����������ַ���abc�����ӡ�����ַ�a,b,c�������г����������ַ���
     abc,acb,bac,bca,cab��cba��
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
˼·���ݹ�
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> result;
vector<string> Permutation(string str) {
	if (str.length() == 0) {
		return result;
	}
	PermutationCore(str, 0);
	sort(str.begin(), str.end());
	return result;
}

void PermutationCore(string str, int begin) {
	if (begin == str.length()) {
		result.push_back(str);
		return;
	}
	for (int i = begin; i < str.length(); i++) {
		if (i != begin && str[i] == str[begin]) {
			continue;
		}
		swap(str[begin], str[i]);
		PermutationCore(str, begin + 1);
	}
}