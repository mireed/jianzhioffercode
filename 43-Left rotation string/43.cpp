//《剑指offer》43.左旋转字符串
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
题目：汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
     对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
     例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
思路1： 翻转法。例如：输入字符串"abcdefg"和数字2，该函数将返回左旋转2位得到的结果"cdefgab";
               第一步：翻转字符串“ab”，得到"ba"；
               第二步：翻转字符串"cdefg"，得到"gfedc"；
               第三步：翻转字符串"bagfedc"，得到"cdefgab"；
               或者：
               第一步：翻转整个字符串"abcdefg",得到"gfedcba"
               第二步：翻转字符串“gfedc”，得到"cdefg"
               第三步：翻转字符串"ba",得到"ab"
思路2：只要把要移动的指针先复制到另一个指针中，然后删除了要移动的字符，再将要移动的字符复制到最后就好了
*/

#include <iostream>
#include <string>

using namespace std;

//思路1，翻转
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

//思路2
string LeftRotateString2(string str, int n) {
	string temp = "";
	temp = str.substr(0, n); //获得字符串s中从第0位开始的长度为n的字符串
	str.erase(0, n);
	str = str + temp;
	return str;
}