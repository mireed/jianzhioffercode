//《剑指offer》05.用两个栈实现队列
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
题目：用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
思路：创建两个栈stack1和stack2，使用两个“先进后出”的栈实现一个“先进先出”的队列。
     
	 我们通过一个具体的例子分析往该队列插入和删除元素的过程。首先插入一个元素a，不妨先把它插入到stack1，此时stack1中的元素有{a}，
	 stack2为空。再压入两个元素b和c，还是插入到stack1中，此时stack1的元素有{a,b,c}，其中c位于栈顶，而stack2仍然是空的。
     这个时候我们试着从队列中删除一个元素。按照先入先出的规则，由于a比b、c先插入队列中，最先删除的元素应该是a。元素a存储在stack1中，
	 但并不在栈顶，因此不能直接进行删除操作。注意stack2我们一直没有使用过，现在是让stack2发挥作用的时候了。如果我们把stack1中的元
	 素逐个弹出压入stack2，元素在stack2中的顺序正好和原来在stack1中的顺序相反。因此经过3次弹出stack1和要入stack2操作之后，stack1为
	 空，而stack2中的元素是{c,b,a}，这个时候就可以弹出stack2的栈顶a了。此时的stack1为空，而stack2的元素为{c,b}，其中b在栈顶。
    
	因此我们的思路是：当stack2中不为空时，在stack2中的栈顶元素是最先进入队列的元素，可以弹出。如果stack2为空时，我们把stack1中的元素
	逐个弹出并压入stack2。由于先进入队列的元素被压倒stack1的栈底，经过弹出和压入之后就处于stack2的栈顶，有可以直接弹出。如果有新元素
	d插入，我们直接把它压入stack1即可。
*/

#include <iostream>
#include <stack>

using namespace std;

stack<int> stack1, stack2;

void push(int node) {
	stack1.push(node);
}

int pop() {
	if (stack2.empty()) {
		while (stack1.size() > 0) {
			int data = stack1.top();
			stack1.pop();
			stack2.push(data);
		}
	}
	int pop_element = stack2.top();
	stack2.pop();
	return pop_element;
}

int main() {

}