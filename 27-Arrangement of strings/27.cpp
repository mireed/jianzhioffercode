//《剑指offer》27.字符串的排列
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
题目：输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc，则打印出由字符a,b,c所能排列出来的所有字符串
     abc,acb,bac,bca,cab和cba。
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
思路：递归
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> result;
vector<string> Permutation(string str) {
	if (str.length() == 0) {
		return result;
	}
	PermutationCore(str, 0);
	sort(str.begin(), str.end());
	return result;
}

void PermutationCore(string str, int begin) {
	if (begin == str.length()) {
		result.push_back(str);
		return;
	}
	for (int i = begin; i < str.length(); i++) {
		if (i != begin && str[i] == str[begin]) {
			continue;
		}
		swap(str[begin], str[i]);
		PermutationCore(str, begin + 1);
	}
}