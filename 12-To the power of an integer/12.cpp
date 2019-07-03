//����ָoffer��12.��ֵ�������η�
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
��Ŀ������һ��double���͵ĸ�����base��int���͵�����exponent����base��exponent�η�������ʹ�ÿ⺯��pow
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
˼·����ָ��Ϊ������ʱ�򣬿����ȶ�ָ�������ֵ��Ȼ������η��Ľ��֮����ȡ�������������Ϊ0����ֱ�ӷ���0����ʱ�Ĵη�����ѧ����û������ġ�
     ����֮�⣬����Ҫע�⣺���ڼ������ʾС��������float��double��С�������������ǲ���ֱ���õȺţ�==���ж�����С���Ƿ���ȡ������
	 ��С���Ĳ�ľ���ֵ��С������С��0.0000001���Ϳ�����Ϊ������ȡ�
     �ڼ���η���ʱ�򣬳��˼򵥵ı��������ǿ���ʹ�ù�ʽ���м��㣬�����ټ�����
*/

#include <iostream>

using namespace std;

double Power(double base, int exponent) {
	if (equal(base, 0.0)) {
		return 0;
	}
	unsigned int absExponent = 0;
	if (exponent > 0) {
		absExponent = (unsigned int)(exponent);
	}
	else {
		absExponent = (unsigned int)(-exponent);
	}
	double result = PowerWithUnsignedExponent(base, absExponent);
	if (exponent < 0) {
		result = 1 / result;
	}
	return result;
}

bool equal(double num1, double num2) {
	if ((num1 - num2) > -0.0000001 && (num1 - num2) < 0.0000001) {
		return true;
	}
	else {
		return false;
	}
}

double PowerWithUnsignedExponent(double base, unsigned int exponent) {
	if (exponent == 0) {
		return 1;
	}
	if (exponent == 1) {
		return base;
	}
	double result = PowerWithUnsignedExponent(base, exponent >> 1);//�����������������2
	result *= result;
	if (exponent & 0x1 == 1) {//λ�������������������������ж�һ��������������ż��
		result *= base;//0x��ͷ�ı�ʾ����ʮ����������k&0x1��ʾk��0x1��λ�룬��Ч��Ϊ
	}//ȡk�Ķ����������ұߵ����֣���ʽҲ���������ж�k����ż�ԣ� ���kΪ�������������Ϊ1������Ϊ0��
	return result;
}

int main() {

}