//《剑指offer》49.把字符串转换成整数
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
题目：将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0。
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
思路：需要注意的要点有：
     指针是否为空指针以及字符串是否为空字符串；
     字符串对于正负号的处理；
     输入值是否为合法值，即小于等于'9'，大于等于'0'；
     int为32位，需要判断是否溢出；
     使用错误标志，区分合法值0和非法值0。
     代码中用两个函数来实现该功能，其中标志位g_nStatus用来表示是否为异常输出，minus标志位用来表示是否为负数。
*/

#include <iostream>
#include <string>

using namespace std;

enum status{kValid = 0, kInvalid};
int g_nStatus = kValid;//用来表示是否为异常输出
int StrToInt(string str) {
	g_nStatus = kInvalid;
	long long num = 0;
	const char* cstr = str.c_str();// c_str()接口是string类的一个函数,返回的是字符串的首地址,返回值类型是const char *的.
	                              //如果要使用它并对其进行赋值操作,必须要使用strcpy函数.如果哦直接进行赋值,是不会赋值成功的.(小
	//判断指针是否为空指针以及字符串是否为空字符串
	if (cstr != NULL && *cstr != '\0') {
		bool minus = false;//用来表示是否为负数,默认是加号
		if (*cstr == '+') {
			cstr++;
		}
		else if (*cstr == '-') {
			minus = true;
			cstr++;
		}
		if(*cstr != '\0') {
			num = StrToIntCore(cstr, minus);
		}
	}
	return (int)num;
}
long long StrToIntCore(const char* cstr, bool minus) {
	long long num = 0;
	while (*cstr != '\0') {
		//判断输入值是否为合法值，即小于等于'9'，大于等于'0'
		if (*cstr >= '0' && *cstr <= '9') {
			int flag = minus ? -1 : 1;
			num = num * 10 + flag * (*cstr - '0');
			//int为32位，需要判断是否溢出
			if ((!minus && num > 0x7fffffff) || (minus && num < (signed int)0x80000000)) {
				num = 0;
				break;
			}
			cstr++;
		}
		else {
			num = 0;
			break;
		}
	}
	//判断是否正常结束
	if (*cstr == '\0') {
		g_nStatus = kValid;
	}
	return num;
}