//����ָoffer��29.��С��K����
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
��Ŀ������n���������ҳ�������С��K��������������4,5,1,6,2,7,3,8��8�����֣�����С��4��������1,2,3,4��
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
˼·����������������߶�����
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> result;
//��1����������
vector<int> GetLeastNumbers_Solution1(vector<int> input, int k) {
	if (input.size() == NULL || k > input.size()) {
		return result;
	}
	sort(input.begin(), input.end());
	for (int i = 0; i < k; i++) {
		result.push_back(input[i]);
	}
	return result;
}

//��2��������
vector<int> GetLeastNumbers_Solution2(vector<int> input, int k) {
	int length = input.size();
	bool change = true;
	if (length <= 0 || k <= 0 || k > length) {
		return result;
	}
	for (int i = 0; i < length; i++) {
		if (result.size() < k) {
			result.push_back(input[i]);
		}
		else{
			if (change == true) {
				//1.�����󶥶�
				for (int j = k / 2; j >= 0; j--) {//�ӵ�һ����Ҷ�ӽڵ�������ϴ������ҵ����ṹ
					HeadAdjust(result, j, k);
				}
				for (int j = k - 1; j > 0; j--) {//2.�����ѽṹ+�����Ѷ�Ԫ����ĩβԪ��
					swap(result[0], result[j]); //���Ѷ�Ԫ����ĩβԪ�ؽ��н���
					HeadAdjust(result, 0, j);//���¶Զѽ��е���
				}
				change = false;
			}
			if (result[k - 1] > input[i]) {
				result[k - 1] = input[i];
				change = true;
			}
		}
	}
	return result;
}


void HeadAdjust(vector<int> &input, int parent, int length) {// �����󶥶ѣ����ǵ������̣������ڴ󶥶��ѹ����Ļ����ϣ�
	int temp = input[parent]; //��ȡ����ǰԪ��i
	int child = 2 * parent + 1;//��i�������ӽ�㿪ʼ��Ҳ����2i+1����ʼ
	while (child < length) {
		if (child + 1 < length && input[child] < input[child + 1]) {//������ӽ��С�����ӽ�㣬kָ�����ӽ��
			child++;
		}
		if (temp >= input[child]) {//����ӽڵ���ڸ��ڵ㣬���ӽڵ�ֵ�������ڵ㣨���ý��н�����
			break;
		}
		input[parent] = input[child];

		parent = child;
		child = 2 * parent + 1;
	}
	input[parent] = temp;//��tempֵ�ŵ����յ�λ��
}