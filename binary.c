


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//检查两棵树是否相同
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	if (p == NULL && q == NULL)
		return true;
	if (p == NULL || q == NULL)
		return false;
	if (p->val != q->val)
		return false;
	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

//给定一个二叉树，找出其最大深度
int maxDepth(struct TreeNode* root) {
	if (root == NULL)
		return 0;
	int left = maxDepth(root->left);//深度记录下来
	int right = maxDepth(root->right);
	return left > right ? left + 1 : right + 1;
}


//检查给定二叉树是否是镜像对称的
bool isSymmetric(struct TreeNode* root) {
	return isMiror(root, root);//从root开始判断（先判断root是否为空，再判断左右子树是否为空或是否有一个为空）
}

int isMiror(struct TreeNode* t1, struct TreeNode* t2) {//给定左子树指针和右子树指针，起点分别问第二、三个结点

	if (t1 == NULL && t2 == NULL)//左右都为空则对称
		return true;
	if (t1 == NULL || t2 == NULL)//左右中有且仅有一个不为空则不对称
		return false;
	return (t1->val == t2->val) && isMiror(t1->left, t2->right) && isMiror(t1->right, t2->left);
}