//����ָoffer��02.�滻�ո�
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
��Ŀ����ʵ��һ����������һ���ַ����еĿո��滻�ɡ�%20�������磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
˼·��(˫ָ��ϵ��)���ǿ����ȱ���һ���ַ����������Ϳ���ͳ�Ƴ��ַ����ո���������������ɴ˼�����滻֮����ַ������ܳ��ȡ�
     ÿ�滻һ���ո񣬳�������2������滻�Ժ��ַ����ĳ��ȵ���ԭ���ĳ��ȼ���2���Կո���Ŀ��
	 ��"We are happy"Ϊ����"We are happy"����ַ����ĳ���Ϊ14��������β����"\n"���������������ո�����滻֮���ַ����ĳ�����18��
    ���Ǵ��ַ�����β����ʼ���ƺ��滻������׼������ָ�룬P1��P2��P1ָ��ԭʼ�ַ�����ĩβ����P2ָ���滻֮����ַ�����ĩβ��
	������������ǰ�ƶ�ָ��P1���������ָ����ַ����Ƶ�P2ָ���λ�ã�ֱ��������һ���ո�Ϊֹ��������һ���ո�֮�󣬰�P1��ǰ�ƶ�1��
	��P2֮ǰ�����ַ���"%20"������"%20"�ĳ���Ϊ3��ͬʱҲҪ��P2��ǰ�ƶ�3��
*/

#include <iostream>
#include <string>

using namespace std;

void replaceSpace(char *str, int length) {
	if (str == NULL || length <= 0) {
		return;
	}
	int original_length = 0;
	int number_blank = 0;
	int i = 0;
	while (str[i++] != '\0') {//�ַ�'\0' : ASCII��Ϊ0����ʾһ���ַ��������ı�־������ת���ַ�
		++original_length;
		while (str[i] == ' ') {
			++number_blank;
		}
	}
	int new_length = original_length + 2 * number_blank;
	int index_orignal = original_length - 1;
	int index_new = new_length - 1;
	while (index_orignal >= 0 && index_new > index_orignal) {
		if (str[index_orignal] == ' ') {
			str[index_new--] = '0';
			str[index_new--] = '2';
			str[index_new--] = '%';
		}
		else {
			str[index_new--] = str[index_orignal];
		}
		--index_orignal;
	}
}

int main() {
	int length;
	cout << "�������ַ������ȣ�" << endl;
	cin >> length;
	char str[100];
	cout << "�������ַ�����" << endl;
	cin.getline(str, length);
	replaceSpace(str, length);
	system("pause");
	return 0;
}