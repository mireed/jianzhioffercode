//����ָoffer��49.���ַ���ת��������
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
��Ŀ����һ���ַ���ת����һ��������Ҫ����ʹ���ַ���ת�������Ŀ⺯���� ��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0��
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
˼·����Ҫע���Ҫ���У�
     ָ���Ƿ�Ϊ��ָ���Լ��ַ����Ƿ�Ϊ���ַ�����
     �ַ������������ŵĴ���
     ����ֵ�Ƿ�Ϊ�Ϸ�ֵ����С�ڵ���'9'�����ڵ���'0'��
     intΪ32λ����Ҫ�ж��Ƿ������
     ʹ�ô����־�����ֺϷ�ֵ0�ͷǷ�ֵ0��
     ������������������ʵ�ָù��ܣ����б�־λg_nStatus������ʾ�Ƿ�Ϊ�쳣�����minus��־λ������ʾ�Ƿ�Ϊ������
*/

#include <iostream>
#include <string>

using namespace std;

enum status{kValid = 0, kInvalid};
int g_nStatus = kValid;//������ʾ�Ƿ�Ϊ�쳣���
int StrToInt(string str) {
	g_nStatus = kInvalid;
	long long num = 0;
	const char* cstr = str.c_str();// c_str()�ӿ���string���һ������,���ص����ַ������׵�ַ,����ֵ������const char *��.
	                              //���Ҫʹ������������и�ֵ����,����Ҫʹ��strcpy����.���Ŷֱ�ӽ��и�ֵ,�ǲ��ḳֵ�ɹ���.(С
	//�ж�ָ���Ƿ�Ϊ��ָ���Լ��ַ����Ƿ�Ϊ���ַ���
	if (cstr != NULL && *cstr != '\0') {
		bool minus = false;//������ʾ�Ƿ�Ϊ����,Ĭ���ǼӺ�
		if (*cstr == '+') {
			cstr++;
		}
		else if (*cstr == '-') {
			minus = true;
			cstr++;
		}
		if(*cstr != '\0') {
			num = StrToIntCore(cstr, minus);
		}
	}
	return (int)num;
}
long long StrToIntCore(const char* cstr, bool minus) {
	long long num = 0;
	while (*cstr != '\0') {
		//�ж�����ֵ�Ƿ�Ϊ�Ϸ�ֵ����С�ڵ���'9'�����ڵ���'0'
		if (*cstr >= '0' && *cstr <= '9') {
			int flag = minus ? -1 : 1;
			num = num * 10 + flag * (*cstr - '0');
			//intΪ32λ����Ҫ�ж��Ƿ����
			if ((!minus && num > 0x7fffffff) || (minus && num < (signed int)0x80000000)) {
				num = 0;
				break;
			}
			cstr++;
		}
		else {
			num = 0;
			break;
		}
	}
	//�ж��Ƿ���������
	if (*cstr == '\0') {
		g_nStatus = kValid;
	}
	return num;
}