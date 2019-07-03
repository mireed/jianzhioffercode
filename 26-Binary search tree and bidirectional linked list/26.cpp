//《剑指offer》26.二叉搜索树与双向链表
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
题目：输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
思路：根据二叉搜索树的特点：左结点的值<根结点的值<右结点的值，我们不难发现，使用二叉树的中序遍历出来的数据的数序，就是排序的顺序。
     因此，首先，确定了二叉搜索树的遍历方法。接下来，我们看下图，我们可以把树分成三个部分：值为10的结点、根结点为6的左子树、根结点
	 为14的右子树。根据排序双向链表的定义，值为10的结点将和它的左子树的最大一个结点链接起来，同时它还将和右子树最小的结点链接起来。
	 按照中序遍历的顺序，当我们遍历到根结点时，它的左子树已经转换成一个排序的好的双向链表了，并且处在链表中最后一个的结点是当前值最
	 大的结点。我们把值为8的结点和根结点链接起来，10就成了最后一个结点，接着我们就去遍历右子树，并把根结点和右子树中最小的结点链接起来。
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

TreeNode* Convert(TreeNode* pRootOfTree) {
	TreeNode* pLastNodeinList = NULL;//记录双向链表尾结点
	ConvertNode(pRootOfTree, &pLastNodeinList);//开始转换节点
	TreeNode* pHeadinList = pLastNodeinList;
	while (pHeadinList != NULL && pHeadinList->left != NULL)
	{
		pHeadinList = pHeadinList->left;
	}
	return pHeadinList;
}

void ConvertNode(TreeNode* pNode, TreeNode** pLastNodeInList) {
	if (pNode == NULL) {//叶节点直接返回
		return;
	}
	TreeNode* pCur = pNode;
	if (pCur->left != NULL) {//递归左子树
		ConvertNode(pCur->left, pLastNodeInList);
	}
	pCur->left = *pLastNodeInList;//左指针
	if (*pLastNodeInList != NULL) {//右指针
		(*pLastNodeInList)->right = pCur;
	}
	*pLastNodeInList = pCur;
	if (pCur->right != NULL) {
		ConvertNode(pCur->right, pLastNodeInList);
	}
}