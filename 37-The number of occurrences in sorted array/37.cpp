//����ָoffer��37.���������������г��ֵĴ���
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
��Ŀ��ͳ��һ�����������������г��ֵĴ�����
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
˼·��ʹ�ö��ַ��ҵ������������г��ֵĵ�һ��λ�ã������ö��ַ��ҵ������������г��ֵĵڶ���λ�á�ʱ�临�Ӷ�ΪO(logn + logn)��
     ���յ�ʱ�临�Ӷ�ΪO(logn)��
     �ٸ����ӣ��ҵ�����k������data�г��ֵĴ�����
     ����data�У�����k���ֵĵ�һ��λ�ã����Ƕ�����data���ж��֣���������м������С��k��˵��kӦ�ó������м�λ�õ��ұߣ�
	 ��������м�����ִ���k��˵��kӦ�ó������м�λ�õ���ߣ���������м�����ֵ���k�������м�λ�õ�ǰһ�����ֲ�����k��
	 ˵������м����־�������k���ֵĵ�һ��λ�á�
     ͬ������k���ֵ����һ��λ�ã�Ҳ�������ҵġ������ж����в�ͬ������ʹ�����������ֱ������ǡ�
*/

#include <iostream>
#include <vector>

using namespace std;

int GetNumberOfK(vector<int> data, int k) {
	if (data.size() == NULL) {
		return 0;
	}
	int first = GetFirstK(data, k, 0, data.size() - 1);
	int last = GetLastK(data, k, 0, data.size() - 1);
	if (first != -1 && last != -1) {
		return last - first + 1;
	}
	return 0;
}

int GetFirstK(vector<int> data, int k, int begin, int end) {
	if (begin > end) {
		return -1;
	}
	int mid = (begin + end) >> 2;
	if (k == data[mid]) {
		if ((mid > 0 && data[mid - 1] != k) || mid == 0) {
			return mid;
		}
		else {
			end = mid - 1;
		}
	}
	else if (k > data[mid]) {
		begin = mid + 1;
	}
	else {
		end = mid - 1;
	}
	return GetFirstK(data, k, begin, end);
}

int GetLastK(vector<int> data, int k, int begin, int end) {
	if (begin > end) {
		return -1;
	}
	int mid = (begin + end) >> 2;
	if (k == data[mid]) {
		if (((mid + 1) < data.size() && data[mid + 1] != k) || mid == data.size() - 1) {
			return mid;
		}
		else {
			begin = mid + 1;
		}
	}
	else if (k > data[mid]) {
		begin = mid + 1;
	}
	else {
		end = mid + 1;
	}
	return GetLastK(data, k, begin, end);
}