


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//����������Ƿ���ͬ
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	if (p == NULL && q == NULL)
		return true;
	if (p == NULL || q == NULL)
		return false;
	if (p->val != q->val)
		return false;
	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

//����һ�����������ҳ���������
int maxDepth(struct TreeNode* root) {
	if (root == NULL)
		return 0;
	int left = maxDepth(root->left);//��ȼ�¼����
	int right = maxDepth(root->right);
	return left > right ? left + 1 : right + 1;
}


//�������������Ƿ��Ǿ���ԳƵ�
bool isSymmetric(struct TreeNode* root) {
	return isMiror(root, root);//��root��ʼ�жϣ����ж�root�Ƿ�Ϊ�գ����ж����������Ƿ�Ϊ�ջ��Ƿ���һ��Ϊ�գ�
}

int isMiror(struct TreeNode* t1, struct TreeNode* t2) {//����������ָ���������ָ�룬���ֱ��ʵڶ����������

	if (t1 == NULL && t2 == NULL)//���Ҷ�Ϊ����Գ�
		return true;
	if (t1 == NULL || t2 == NULL)//���������ҽ���һ����Ϊ���򲻶Գ�
		return false;
	return (t1->val == t2->val) && isMiror(t1->left, t2->right) && isMiror(t1->right, t2->left);
}