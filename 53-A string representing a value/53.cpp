//����ָoffer��53.��ʾ��ֵ���ַ���
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
��Ŀ����ʵ��һ�����������ж��ַ����Ƿ��ʾ��ֵ������������С���������磬�ַ���"+100","5e2","-123","3.1416"��"-1E-16"����ʾ��ֵ�� 
      ����"12e","1a3.14","1.2.3","+-5"��"12e+4.3"�����ǡ�
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
˼·���ж�һ���ַ����Ƿ��������ģʽʱ�����ȿ���һ���ַ��ǲ��������š�����ǣ����ַ������ƶ�һ���ַ�������ɨ��ʣ����ַ�����0��9����λ��
      �����һ��С����������С���㡣���⣬������ÿ�ѧ��������ʾ����ֵ������������С���ĺ��滹�п�������'e'����'E'��
*/

#include <iostream>

using namespace std;

// ���ֵĸ�ʽ������A[.[B]][e|EC]����.B[e|EC]��ʾ��
// ����A��C���������������������ţ�Ҳ����û�У�
// ��B��һ���޷�������
bool isNumeric(char* string) {
	if (string == NULL || *string == '\0') {
		return false;
	}
	if (*string == '+' || *string == '-') {
		++string;
	}
	bool numeric = true;
	scanDigits(&string);
	if (*string != '\0') {
		if (*string == '.') {
			++string;
			scanDigits(&string);
			if (*string == 'e' || *string == 'E') {
				numeric = isExponential(&string);
			}
		}
		else if (*string == 'e' || *string == 'E') {
			numeric = isExponential(&string);
		}
		else {
			numeric = false;
		}
	}
	return numeric && *string == '\0';
}
// ɨ�����֣����ںϷ����֣�ֱ������
void scanDigits(char** string) {
	while (**string != '\0' && **string >= '0' && **string <= '9') {
		++(*string);
	}
}
// �����жϿ�ѧ��������ʾ����ֵ�Ľ�β�����Ƿ�Ϸ�
bool isExponential(char** string) {
	++(*string);
	if (**string == '+' || **string == '-') {
		++(*string);
	}
	if (**string == '\0') {
		return false;
	}
	scanDigits(string);
	return (**string == '\0') ? true : false;
}