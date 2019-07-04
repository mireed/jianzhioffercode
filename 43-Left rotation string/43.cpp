//����ָoffer��43.����ת�ַ���
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
��Ŀ�������������һ����λָ�����ѭ�����ƣ�ROL���������и��򵥵����񣬾������ַ���ģ�����ָ�����������
     ����һ���������ַ�����S���������ѭ������Kλ������������
     ���磬�ַ�����S=��abcXYZdef��,Ҫ�����ѭ������3λ��Ľ��������XYZdefabc�����ǲ��Ǻܼ򵥣�OK���㶨����
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
˼·1�� ��ת�������磺�����ַ���"abcdefg"������2���ú�������������ת2λ�õ��Ľ��"cdefgab";
               ��һ������ת�ַ�����ab�����õ�"ba"��
               �ڶ�������ת�ַ���"cdefg"���õ�"gfedc"��
               ����������ת�ַ���"bagfedc"���õ�"cdefgab"��
               ���ߣ�
               ��һ������ת�����ַ���"abcdefg",�õ�"gfedcba"
               �ڶ�������ת�ַ�����gfedc�����õ�"cdefg"
               ����������ת�ַ���"ba",�õ�"ab"
˼·2��ֻҪ��Ҫ�ƶ���ָ���ȸ��Ƶ���һ��ָ���У�Ȼ��ɾ����Ҫ�ƶ����ַ����ٽ�Ҫ�ƶ����ַ����Ƶ����ͺ���
*/

#include <iostream>
#include <string>

using namespace std;

//˼·1����ת
string LeftRotateString1(string str, int n) {
	string result = str;
	int length = str.size();
	if (length < 0) {
		return NULL;
	}
	if (n >= 0 && n <= length) {
		int left1 = 0, right1 = n - 1;
		int left2 = n, right2 = length - 1;
		ReverseString(result, left1, right1);
		ReverseString(result, left2, right2);
		ReverseString(result, left1, right2);
	}
	return result;
}
void ReverseString(string &str, int begin, int end) {
	while (begin < end) {
		swap(str[begin++], str[end--]);
	}
}

//˼·2
string LeftRotateString2(string str, int n) {
	string temp = "";
	temp = str.substr(0, n); //����ַ���s�дӵ�0λ��ʼ�ĳ���Ϊn���ַ���
	str.erase(0, n);
	str = str + temp;
	return str;
}