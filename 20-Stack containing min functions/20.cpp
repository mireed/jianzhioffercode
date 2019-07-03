//《剑指offer》20.包含min函数的栈
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
题目：定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
思路：使用两个stack，一个为数据栈，另一个为辅助栈。数据栈用于存储所有数据，辅助栈用于存储最小值。
     举个例子：
     入栈的时候：首先往空的数据栈里压入数字3，显然现在3是最小值，我们也把最小值压入辅助栈。接下来往数据栈里压入数字4。
	 由于4大于之前的最小值，因此我们只要入数据栈，不压入辅助栈。出栈的时候：当数据栈和辅助栈的栈顶元素相同的时候，辅助
	 栈的栈顶元素出栈。否则，数据栈的栈顶元素出栈。获得栈顶元素的时候：直接返回数据栈的栈顶元素。栈最小元素：直接返回辅助栈的栈顶元素。
*/

#include <iostream>
#include <stack>

using namespace std;

stack<int> Data;
stack<int> Min;

void push(int value) {
	Data.push(value);
	if (Min.empty()) {
		Min.push(value);
	}
	if (Min.top() > value) {
		Min.push(value);
	}
}

void pop() {
	if (Data.top() == Min.top()) {
		Min.pop();
	}
	Data.pop();
}

int top() {
	return Data.top();
}

int min() {
	return Min.top();
}