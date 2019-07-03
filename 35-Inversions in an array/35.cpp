//����ָoffer��35.��һ��ֻ����һ�ε��ַ�
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
��Ŀ���������е��������֣����ǰ��һ�����ִ��ں�������֣����������������һ������ԡ�����һ������,�����������е�����Ե�����P��
     ����P��1000000007ȡģ�Ľ������� �����P%1000000007��
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
˼·������˼�룬���ù鲢�����˼·������
     ����һ���鲢����ĺϲ����̣���Ҫ�ǿ��Ǻϲ�������������ʱ���������������
     ���������������У����������±꣺�����������е�ĩβ��ÿ�αȽ�����ĩβֵ�����ǰĩβ���ں�ĩβֵ�����С������е�ǰ���ȡ�������ԣ�
	 ���򲻹�������ԡ�Ȼ��ѽϴ�ֵ���������������ĩβ��������Ҫ�������������кϲ����������鲢����
     ������ÿ���ںϲ�ǰ���ȵݹ�ش������Ρ��Ұ�Σ������Ұ�����������Ұ�ε���������ɵõ����ټ������Ұ�κϲ�ʱ����Եĸ�����
*/

#include <iostream>
#include <vector>

using namespace std;

int InversePairs(vector<int> data) {
	if (data.size() == 0) {
		return 0;
	}
	vector<int> copy;//����ĸ�������
	for (int i = 0; i < data.size(); i++) {
		copy.push_back(data[i]);
	}
	return InversePairsCore(data, copy, 0, data.size() - 1) % 1000000007;
}

long InversePairsCore(vector<int> &data, vector<int> &copy, int begin, int end) {
	if (begin == end) {//���ָ���е㣬��û�������
		copy[begin] = data[end];
		return 0;
	}
	int mid = (begin + end) >> 2;//���е�
	int leftcount = InversePairsCore(copy, data, begin, mid);//ʹdata�������򣬲�������������Ե���Ŀ
	int rightcount = InversePairsCore(copy, data, mid + 1, end);//ʹdata�Ұ�����򣬲������Ұ������Ե���Ŀ
	int i = mid; // i��ʼ��Ϊǰ������һ�����ֵ��±�
	int j = end; // j��ʼ��Ϊ�������һ�����ֵ��±�
	int indexcopy = end; // �������鸴�Ƶ���������һ�����ֵ��±�
	long count = 0; // ����������Եĸ�����ע������
	while (i >= begin && j >= mid + 1) {
		if (data[i] > data[j]) {
			copy[indexcopy--] = data[i--];
			count += j - mid;
		}
		else {
			copy[indexcopy--] = data[j--];
		}
	}
	for (; i >= begin; --i) {
		copy[indexcopy--] = data[i];
	}
	for (; j >= mid + 1; --j) {
		copy[indexcopy--] = data[j];
	}
	return leftcount + rightcount + count;
}