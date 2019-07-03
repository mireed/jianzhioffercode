//《剑指offer》34.第一个只出现一次的字符
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
题目：在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,
     并返回它的位置, 如果没有则返回 -1（需要区分大小写）.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
思路：建立一个哈希表，第一次扫描的时候，统计每个字符的出现次数。第二次扫描的时候，如果该字符出现的次数为1，则返回这个字符的位置。
*/

#include <iostream>
#include <unordered_map>

using namespace std;

int FirstNotRepeatingChar(string str) {
	if (str.length() == 0) {
		return -1;
	}
	unordered_map<char, int> m;
	for (int i = 0; i < str.length(); i++) {
		m[str[i]]++;
	}
	for (int i = 0; i < str.length(); i++) {
		if (m[str[i]] == 1) {
			return i;
		}
	}
	return -1;
}