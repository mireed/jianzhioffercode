//����ָoffer��44.��ת����˳������
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
��Ŀ��ţ���������һ����Ա��Fish��ÿ���糿���ǻ�����һ��Ӣ����־��дЩ�����ڱ����ϡ�ͬ��Cat��Fishд�������ĸ���Ȥ��
     ��һ������Fish������������ȴ������������˼�����磬��student. a am I������������ʶ������һ�ԭ���Ѿ��ӵ��ʵ�˳��ת�ˣ�
     ��ȷ�ľ���Ӧ���ǡ�I am a student.����Cat��һһ�ķ�ת��Щ����˳��ɲ����У����ܰ�����ô��
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
˼·��ֻ��Ҫ��ÿ����������ת��Ȼ������������ת�͵õ�����ȷ�Ľ����
*/

#include <iostream>
#include <string>

using namespace std;

string ReverseSentence(string str) {
	string result = str;
	int length = str.size();
	if (length == 0) {
		return "";
	}
	result += ' ';//׷��һ���ո���Ϊ��ת��־λ
	int mark = 0;
	for (int i = 0; i < length; i++) {
		if (result[i] = ' ') {
			Reverse(result, mark, i - 1);
			mark = i + 1;
		}
	}
	result = result.substr(0, length);
	Reverse(result, 0, length - 1);
	return result;
}
void Reverse(string &str, int begin, int end) {
	while (begin < end) {
		swap(str[begin++], str[end--]);
	}
}