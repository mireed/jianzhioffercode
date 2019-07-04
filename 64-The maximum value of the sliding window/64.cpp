//����ָoffer��64.�������ڵ����ֵ
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
��Ŀ������һ������ͻ������ڵĴ�С���ҳ����л�����������ֵ�����ֵ��
     ���磬�����������{2,3,4,2,6,2,5,1}���������ڵĴ�С3����ôһ������6���������ڣ����ǵ����ֵ�ֱ�Ϊ{4,4,6,6,6,5}��
     �������{2,3,4,2,6,2,5,1}�Ļ�������������6���� {[2,3,4],2,6,2,5,1}�� {2,[3,4,2],6,2,5,1}�� {2,3,[4,2,6],2,5,1}��
	 {2,3,4,[2,6,2],5,1}�� {2,3,4,2,[6,2,5],1}�� {2,3,4,2,6,[2,5,1]}��
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
˼·��������STL�е�deque��ʵ�֣�����������������{2,3,4,2,6,2,5,1}Ϊ������ϸ˵����˼·��
     ����ĵ�һ��������2��������������С��ڶ���������3����2������2�������ǻ��������е����ֵ��
	 ��˰�2�Ӷ�����ɾ�����ٰ�3��������С�������������4����3��ͬ����ɾ3��4��
	 ��ʱ�����������Ѿ���3�����֣����������ֵ4λ�ڶ��е�ͷ����
     ���ĸ�����2��4С�����ǵ�4����֮���������п��ܳ�Ϊ���ֵ�ģ��������ǰ�2������е�β����
	 ��һ��������6����4��2����ɾ4��2����6�����������ν��У����ֵ��Զλ�ڶ��е�ͷ����
     �������������жϻ��������Ƿ����һ�����֣�Ӧ���ڶ����������������������±꣬��������ֵ��
	 ��һ�����ֵ��±��뵱ǰ���������ֵ��±�֮����ڻ�������ڻ������ڴ�Сʱ����������Ѿ��Ӵ����л��������ԴӶ�����ɾ����
*/
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
	deque<int> q;
	vector<int> maxInWindows;
	if (num.size() >= size && size >= 1) {
		for (unsigned int i = 0; i < size; i++) {
			while (!q.empty() && num[i] >= num[q.back()]) {
				q.pop_back();
			}
			q.push_back(i);
		}
		for (unsigned int i = size; i < num.size(); i++) {
			maxInWindows.push_back(num[q.front()]);
			while (!q.empty() && num[i] >= num[q.back()]) {
				q.pop_back();
			}
			if (!q.empty() && q.front() <= (int)(i - size)) {
				q.pop_front();
			}
			q.push_back(i);
		}
		maxInWindows.push_back(num[q.front()]);
	}
	return maxInWindows;
}