//����ָoffer��40.������ֻ����һ�ε�����
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
��Ŀ��һ�����������������������֮�⣬���������ֶ����������Ρ���д�����ҳ�������ֻ����һ�ε����֡�
       Ҫ��ʱ�临�Ӷ���O(n)���ռ临�Ӷ���O(1)��
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
˼·��˳��ɨ�跨���������ַ�����ʱ�临�Ӷ���O��n^2���������ù�ϣ��ķ��������ǿռ临�ӶȲ���O��1����
     ����һ�������ǣ��κ�һ������������Լ�������0
	 ��ͷ��βһ����������е�ÿһ�����֣���ô���յõ��Ľ����������ֻ����һ�ε�������������
	 ��Ϊ�������ֶ����������Σ��������ȫ�������ˡ������������ֿ϶���һ������ô���Ľ���϶���Ϊ0��
	 Ҳ����˵����������Ķ����Ʊ�ʾ������һ��λΪ1�������ڽ���������ҵ���һ��Ϊ1��λ��λ�ã���Ϊ��nλ��
	 ���������Ե�nλ�ǲ���1Ϊ��׼��Ԫ�����е����ֳַ����������飬��һ����������ÿ�����ֵĵ�nλ����1������
	 ������������ÿ�����ֵĵ�nλ����0��
*/
#include <iostream>
#include <vector>

using namespace std;

void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
	if (data.size() < 2) {
		return;
	}
	int resultExclusiveOR = 0;
	for (int i = 0; i < data.size(); i++) {
		resultExclusiveOR ^= data[i];
	}
	unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);
	*num1 = *num2 = 0;
	for (int i = 0; i < data.size(); i++) {
		if (IsBit1(data[i], indexOf1)) {
			*num1 ^= data[i];
		 }
		else {
			*num2 ^= data[i];
		}
	}
}

unsigned int FindFirstBitIs1(int num) {//�ҵ���������num��һ��Ϊ1��λ��������0010����һ��Ϊ1��λ����2
	unsigned int indexBit = 0;
	while ((num & 1) == 0 && (indexBit < 8 * sizeof(unsigned int))) {// ֻ�ж�һ���ֽڵ�
		num = num >> 1;//������1λ
		indexBit++;
	}
	return indexBit;
}

bool IsBit1(int num, unsigned int indexBit) {// �жϵ�indexBitλ�Ƿ�Ϊ1
	num = num >> indexBit;
	return (num & 1);
}