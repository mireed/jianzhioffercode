//《剑指offer》17.树的子结构
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
题目：输入两颗二叉树A，B，判断B是不是A的子结构。（PS：我们约定空树不是任意一个树的子结构）。
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
思路：要查找树A中是否存在和树B结构一样的子树，我们可以分为两步：第一步在树A中找到和B的根结
      点的值一样的结点R，第二步再判断树A中以R为根节点的子树是不是包含和树B一样的结构
*/

#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {}
};

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
	bool result = false;
	if (pRoot1 != NULL && pRoot2 != NULL) {
		if (pRoot1->val == pRoot2->val) {
			result = DoesTree1HasTree2(pRoot1, pRoot2);
		}
		if (!result) {
			result = HasSubtree(pRoot1->left, pRoot2);
		}
		if (!result) {
			result = HasSubtree(pRoot1->right, pRoot2);
		}
	}
	return result;
}

bool DoesTree1HasTree2(TreeNode* pRoot1, TreeNode* pRoot2) {
	if (pRoot1 == NULL) {
		return false;
	}
	if (pRoot2 == NULL) {
		return true;
	}
	if (pRoot1->val != pRoot2->val) {
		return false;
	}
	return DoesTree1HasTree2(pRoot1->right, pRoot2->right) && DoesTree1HasTree2(pRoot1->left, pRoot2->left);
}

int main() {

}