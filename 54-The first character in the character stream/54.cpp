//����ָoffer��54.�ַ����е�һ�����ظ����ַ�
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
��Ŀ����ʵ��һ�����������ҳ��ַ����е�һ��ֻ����һ�ε��ַ������磬�����ַ�����ֻ����ǰ�����ַ�"go"ʱ����һ��ֻ����һ�ε��ַ���"g"��
      ���Ӹ��ַ����ж���ǰ�����ַ���google"ʱ����һ��ֻ����һ�ε��ַ���"l"�������ǰ�ַ���û�д��ڳ���һ�ε��ַ�������#�ַ�
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
˼·������⻹�Ǻܼ򵥵ġ����ֽ�������������ͨ����ϣ��ͳ���ַ�����ÿ���ַ����ֵĴ�����˳�㽫�ַ���������string�У�Ȼ���ٱ���string��
     �ӹ�ϣ�����ҵ���һ������һ�ε��ַ���
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string s;
unordered_map<string, int> count;

//Insert one char from stringstream
void Insert(char ch) {
	s += ch;
	++count[ch];
}
//return the first appearence once char in current stringstream
char FirstAppearingOnce() {
	int length = s.size();
	for (int i = 0; i < length; i++) {
		if (count[s[i]] == 1) {
			return s[i];
		}
	}
	return '#';
}