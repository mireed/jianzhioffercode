//《剑指offer》53.表示数值的字符串
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
题目：请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 
      但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
思路：判断一个字符串是否符合上述模式时，首先看第一个字符是不是正负号。如果是，在字符串上移动一个字符，继续扫描剩余的字符串中0到9的数位。
      如果是一个小数，则将遇到小数点。另外，如果是用科学记数法表示的数值，在整数或者小数的后面还有可能遇到'e'或者'E'。
*/

#include <iostream>

using namespace std;

// 数字的格式可以用A[.[B]][e|EC]或者.B[e|EC]表示，
// 其中A和C都是整数（可以有正负号，也可以没有）
// 而B是一个无符号整数
bool isNumeric(char* string) {
	if (string == NULL || *string == '\0') {
		return false;
	}
	if (*string == '+' || *string == '-') {
		++string;
	}
	bool numeric = true;
	scanDigits(&string);
	if (*string != '\0') {
		if (*string == '.') {
			++string;
			scanDigits(&string);
			if (*string == 'e' || *string == 'E') {
				numeric = isExponential(&string);
			}
		}
		else if (*string == 'e' || *string == 'E') {
			numeric = isExponential(&string);
		}
		else {
			numeric = false;
		}
	}
	return numeric && *string == '\0';
}
// 扫描数字，对于合法数字，直接跳过
void scanDigits(char** string) {
	while (**string != '\0' && **string >= '0' && **string <= '9') {
		++(*string);
	}
}
// 用来判断科学计数法表示的数值的结尾部分是否合法
bool isExponential(char** string) {
	++(*string);
	if (**string == '+' || **string == '-') {
		++(*string);
	}
	if (**string == '\0') {
		return false;
	}
	scanDigits(string);
	return (**string == '\0') ? true : false;
}