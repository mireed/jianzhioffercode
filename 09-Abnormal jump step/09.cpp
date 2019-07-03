//《剑指offer》09.变态跳台阶
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
题目：一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
思路：当n=1时，结果为1；
      当n=2时，结果为2；
      当n=3时，结果为4；
      以此类推，我们使用数学归纳法不难发现，跳法f(n)=2^(n-1)。
*/

#include <iostream>

using namespace std;

int jumpFloorII(int number) {
	if (number <= 0) {
		return 0;
	}
	int fn = 1;
	for (int i = 1; i < number; i++) {
		fn *= 2;
	}
	return fn;
}

int main() {

}