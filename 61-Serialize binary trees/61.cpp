//����ָoffer��61.���л�������
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
��Ŀ����ʵ�������������ֱ��������л��ͷ����л���������
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
˼·�������˼·�򵥣�ʹ��ǰ����������л��ͷ����л����ɡ�ֻҪ�Լ�д�ĳ����ʽ��Ӧ�ϼ��ɡ�
     ����ʹ��$���ű�ʾNULL��ͬʱÿ�����֮�䣬��Ҫ��Ӷ��ţ���','���зָ���
*/

#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {}
};

char* Serialize(TreeNode *root) {
	if (!root) {
		return NULL;
	}
	string str;
	SerializeCore(root, str);
	// ��str����ת��Ϊ�ַ�������
	int length = str.length();
	char* res = new char[length + 1];
	// ��str����ת��Ϊ�ַ�������
	for (int i = 0; i < length; i++) {
		res[i] = str[i];
	}
	res[length] = '\0';
	return res;
}

TreeNode* Deserialize(char *str) {
	if (!str) {
		return NULL;
	}
	TreeNode* res = DeserializeCore(&str);
	return res;
}

void SerializeCore(TreeNode* root, string& str) {
	// ���ָ��Ϊ�գ���ʾ���ӽڵ�����ӽڵ�Ϊ�գ�������������#��ʾ
	if (!root) {
		str += '#';
		return;
	}
	string tmp = to_string(root->val);
	str += tmp;
	// �Ӷ��ţ���������ÿ�����
	str += ',';
	SerializeCore(root->left, str);
	SerializeCore(root->right, str);
}

// �ݹ�ʱ�ı���strֵʹ��ָ���������У����Ҫ����Ϊchar**
TreeNode* DeserializeCore(char** str) {
	// ����Ҷ�ڵ�ʱ���������Σ�������null�����Թ�����ϣ����ظ��ڵ�Ĺ���
	if (**str == '#') {
		(*str)++;
		return NULL;
	}
	// ��Ϊ���������ַ�����ʾ��һ���ַ���ʾһλ���Ƚ���ת��
	int num = 0;
	while (**str != ',' && **str != '\0') {
		num = num * 10 + ((**str) - '0');
		(*str)++;
	}
	TreeNode* root = new TreeNode(num);
	if (**str == '\0') {
		return root;
	}
	else {
		(*str)++;
	}
	root->left = DeserializeCore(str);
	root->right = DeserializeCore(str);
	return root;
}