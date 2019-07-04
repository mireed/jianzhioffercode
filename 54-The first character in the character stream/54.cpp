//《剑指offer》54.字符流中第一个不重复的字符
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
题目：请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
      当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。如果当前字符流没有存在出现一次的字符，返回#字符
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
思路：这道题还是很简单的。将字节流保存起来，通过哈希表统计字符流中每个字符出现的次数，顺便将字符流保存在string中，然后再遍历string，
     从哈希表中找到第一个出现一次的字符。
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