//《剑指offer》45.扑克牌顺子
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
题目：LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张😊)...
     他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票,嘿嘿！！
     “红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....LL不高兴了,他想了想,决定大\小王可以看成任何数字,
     并且A看作1,J为11,Q为12,K为13。上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。LL决定去买体育彩票啦。 
     现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的运气如何。为了方便起见,你可以认为大小王是0。
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
思路：提取主要信息，满足如下条件才可以认为是顺子：
      输入数据个数为5；
      输入数据都在0-13之间；
      没有相同的数字；
      最大值与最小值的差值不大于5。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool IsContinuous1(vector<int> numbers) {
	if (numbers.size() < 5) {
		return false;
	}
	int max = -1, min = 14;
	int flag = 0;//记录每个数字出现的次数
	for (int i = 0; i < numbers.size(); i++) {
		int curNum = numbers[i];
		if (curNum < 0 || curNum > 13) {
			return false;
		}
		if (curNum == 0) {// 大小王，可以模拟任意数
			continue;
		}
		if ((flag >> curNum) & 1 == 1) {// 如果数字出现了一次
			return false;
		}
		flag |= 1 << curNum;// 按位保存数字出现次数，比如0110表示，0出现0次，1出现1次，2出现1次，3出现0次。
		if (curNum < min) {// 更新最小值
			min = curNum;
		}
		if (curNum > max) {// 更新最大值
			max = curNum;
		}
		if (max - min >= 5) {// 超过范围一定不是顺子
			return false;
		}
	}
	return true;
}


bool IsContinuous2(vector<int> numbers) {
		int length = numbers.size();
		if (length < 5) {
			return false;
		}
		sort(numbers.begin(), numbers.end(), bijiao);
		int numberOfZero = 0;
		int numberOfGap = 0;
		//统计数组中0的个数
		for (int i = 0; i < length && numbers[i] == 0; i++) {
			++numberOfZero;
		}
		//统计数组中间隔个数
		int small = numberOfZero;
		int big = small + 1;
		while (big < length) {
			//两个数相等，有对子，不可能是顺子
			if (numbers[small] == numbers[big]) {
				return false;
			}
			numberOfGap += numbers[big] - numbers[small] - 1;
			small = big;
			++big;
		}
		return (numberOfGap > numberOfZero) ? false : true;
	}
	static bool bijiao(int a, int b)
	{
		string sb = to_string(a) + to_string(b);
		string sa = to_string(b) + to_string(a);
		if (sb<sa)
			return true;
		else
			return false;
}
