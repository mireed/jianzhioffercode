//����ָoffer��42.�ͺ�ΪS����������
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
��Ŀ������һ����������������һ������S���������в�����������ʹ�����ǵĺ�������S������ж�����ֵĺ͵���S������������ĳ˻���С�ġ�
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
˼·������һ�����飬���ǿ��Զ�������ָ�룬һ���������ұ�����pleft������һ���������������pright����
     ���ȣ����ǱȽϵ�һ�����ֺ����һ�����ֵĺ�curSum���������sum�����curSum < sum����ô���Ǿ�Ҫ�Ӵ�����ֵ��
     ���ԣ�pleft�����ƶ�һλ���ظ�֮ǰ�ļ��㣻���curSum > sum����ô���Ǿ�Ҫ��С����ֵ��
     ���ԣ�pright�����ƶ�һλ���ظ�֮ǰ�ļ��㣻�����ȣ���ô���������־�������Ҫ�ҵ����֣�ֱ��������ɡ�
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> FindNumbersWithSum(vector<int> array, int sum) {
	vector<int> result;
	if (array.size() < 1) {
		return result;
	}
	int left = 0;
	int right = array.size() - 1;
	int curSum = array[left] + array[right];
	while (left < right) {
		if (curSum < sum) {
			left++;
		}
		else if (curSum > sum) {
			right--;
		}
		else {
			result.push_back[array[left]];
			result.push_back[array[right]];
			break;
		}
	}
	return result;
}

