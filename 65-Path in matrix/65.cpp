//����ָoffer��65.�����е�·��
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
��Ŀ�������һ�������������ж���һ���������Ƿ����һ������ĳ�ַ��������ַ���·����
      ·�����ԴӾ����е�����һ�����ӿ�ʼ��ÿһ�������ھ������������ң����ϣ������ƶ�һ�����ӡ�
      ���һ��·�������˾����е�ĳһ�����ӣ���֮�����ٴν���������ӡ� 
      ���� a b c e s f c s a d e e ������3 X 4 �����а���һ���ַ���"bcced"��·�������Ǿ����в�����"abcb"·����
      ��Ϊ�ַ����ĵ�һ���ַ�bռ���˾����еĵ�һ�еڶ�������֮��·�������ٴν���ø���
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
˼·������һ�������û��ݷ�����ĵ������⡣
      ���ȣ���������������Ǻ����׾����ҵ����ַ���str�е�һ���ַ���ͬ�ľ���Ԫ��ch��
	  Ȼ�����ch�����������ĸ��ַ�������к��ַ���str����һ���ַ���ͬ�ģ��Ͱ��Ǹ��ַ�������һ���ַ�����һ�α�������㣩��
	  ���û�У�����Ҫ���˵���һ���ַ���Ȼ�����±�����Ϊ�˱���·���ص�����Ҫһ��������������¼·�������
     ��������У�����������Ϊ��row��col���ĸ��Ӻ�·���ַ������±�ΪpathLength���ַ�һ��ʱ��
	 ��4�����ڵĸ��ӣ�row��col-1������row-1��col������row��col+1���Լ���row+1��col����ȥ��λ·���ַ������±�ΪpathLength+1���ַ���
     ���4�����ڵĸ��Ӷ�û��ƥ���ַ������±�ΪpathLength+1���ַ���������ǰ·���ַ������±�ΪpathLength���ַ��ھ����еĶ�λ����ȷ��
	 ������Ҫ�ص�ǰһ���ַ�����pathLength-1����Ȼ�����¶�λ��
     һֱ�ظ�������̣�ֱ��·���ַ����������ַ����ھ������ҵ���ʽ��λ�ã���ʱstr[pathLength] == '\0'����
*/

#include <iostream>
#include <vector>

using namespace std;

bool hasPath(char* matrix, int rows, int cols, char* str) {
	if (matrix == NULL || rows < 1 || cols < 1 || str == NULL) {
		return NULL;
	}
	bool* visited = new bool[rows * cols];
	memset(visited, 0, rows * cols);//��ĳһ���ڴ��е�����ȫ������Ϊָ����ֵ�� �������ͨ��Ϊ��������ڴ�����ʼ��������
	int PathLength = 0;
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			if (hasPathCore(matrix, rows, cols, row, col, str, PathLength, visited)) {
				delete[] visited;
				return true;
			}
		}
	}
}
bool hasPathCore(char* matrix, int rows, int cols, int row, int col, char* str, int& pathLength, bool* visited) {
	if (str[pathLength] == '\0') {
		return true;
	}
	bool hasPath = false;
	if (row >= 0 && row < rows && col >= 0 && col < cols && matrix[row * cols + col] == str[pathLength] && !visited[row * cols + col]) {
		++pathLength;
		visited[row * cols + col] = true;
		hasPath = hasPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visited) ||
			hasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visited) ||
			hasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visited) ||
			hasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visited);
		if (!hasPath) {
			--pathLength;
			visited[row * cols + col] = false;
		}
	}
	return hasPath;
}