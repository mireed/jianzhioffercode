//《剑指offer》02.替换空格
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
题目：请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
思路：(双指针系列)我们可以先遍历一次字符串，这样就可以统计出字符串空格的总数，并可以由此计算出替换之后的字符串的总长度。
     每替换一个空格，长度增加2，因此替换以后字符串的长度等于原来的长度加上2乘以空格数目。
	 以"We are happy"为例，"We are happy"这个字符串的长度为14（包括结尾符号"\n"），里面有两个空格，因此替换之后字符串的长度是18。
    我们从字符串的尾部开始复制和替换。首先准备两个指针，P1和P2，P1指向原始字符串的末尾，而P2指向替换之后的字符串的末尾。
	接下来我们向前移动指针P1，逐个把它指向的字符复制到P2指向的位置，直到碰到第一个空格为止。碰到第一个空格之后，把P1向前移动1格，
	在P2之前插入字符串"%20"。由于"%20"的长度为3，同时也要把P2向前移动3格。
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
	while (str[i++] != '\0') {//字符'\0' : ASCII码为0，表示一个字符串结束的标志。这是转义字符
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
	cout << "请输入字符串长度：" << endl;
	cin >> length;
	char str[100];
	cout << "请输入字符串：" << endl;
	cin.getline(str, length);
	replaceSpace(str, length);
	system("pause");
	return 0;
}