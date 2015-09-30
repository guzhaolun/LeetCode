#include <iostream>
#include <queue>
#include <stack>
using namespace std;
//Definition for a binary tree node.
 struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution
{
public:
	//ֱ����queue������α�������ʱ�ˡ���
	int countNodes(TreeNode* root)
	{
		if (!root)
			return 0;
		queue<TreeNode*> q;
		q.push(root);
		int count = 1;
		while (!q.empty())
		{
			TreeNode* t = q.front();
			q.pop();
			if (t->left)
			{
				q.push(t->left);
				count++;
			}
			if (t->right)
			{
				q.push(t->right);
				count++;

			}
		}
		return count;
	}

	//O(lgn^2)���ݹ�����֪�������������߶���ȡ�
	int countNodes2(TreeNode* root)
	{
		if (!root)
			return 0;
		int count1 = 0,count2=0;
		TreeNode* temp = root;
		while (temp->right)
		{
			count1++;
			temp = temp->right;
		}

		temp = root;
		while (temp->left)
		{
			count2++;
			temp = temp->left;
		}
		int total = pow(2, count1 + 1) - 1;
		if (count1 == count2)
			return total;
		else
			return countNodes2(root->left) + countNodes2(root->right) + 1;
	}

	//��������һ�ּ��д������
	int countNodes3(TreeNode* root) {
		if (root == NULL) {
			return 0;
		}
		int cnt = 1;
		cnt += countNodes3(root->left) + countNodes3(root->right);
		return cnt;
	}

	int countNodes4(TreeNode* root) {
		if (root == NULL) {
			return 0;
		}
		int elen = 0;
		TreeNode* cur = root;

		while (cur != NULL) {
			elen++;
			cur = cur->left;
		}

		// amount of nodes above last level in the tree
		int cnt = (1 << (elen - 1)) - 1;
		return cnt + last_level_count(root, elen);

	}

	//�������һ��Ľڵ��������������ã����������˺ü�������
	//�����ǲ����������ĸ߶ȿ��Ƿ�����������
	//�͵�һ�ֱȽϣ�ÿ��ֻѭ�������������ù������������ӶȽ���һ�롣
	int last_level_count(TreeNode* root, int elen) {
		if (root == NULL || elen <= 0) 
		{
			return 0;
		}
		if (elen == 1) 
		{
			return 1;
		}
		TreeNode* cur = root->left;
		int lcnt = elen - 1;
		while (cur != NULL) 
		{
			lcnt--;
			cur = cur->right;
		}

		// left sub-tree is not full, no need to compute right sub-tree
		if (lcnt != 0) {
			return last_level_count(root->left, elen - 1);
		}
		// left sub-tree is full
		int level_count_left_subtree = 1 << (elen - 1 - 1);
		int level_count_right_subtree = last_level_count(root->right, elen - 1);

		return level_count_left_subtree + level_count_right_subtree;
	}

	//����������˼��һ�����ĳ���ѭ�����ٶ��ֿ��ˡ��������99%������
	int countNodes5(TreeNode* root) {
		if (!root) return 0;
		TreeNode *temp = root;
		int height = 0, count = 0, level;
		while (temp) {
			temp = temp->left;
			height++;
		}
		temp = root;
		level = height - 2;
		while (level >= 0) {
			TreeNode *left = temp->left;
			for (int i = 0; i < level; i++) {
				left = left->right;
			}
			if (left) {
				temp = temp->right;
				count += (1 << level);
			}
			else temp = temp->left;
			level--;
		}
		if (temp) count++;
		return (1 << (height - 1)) + count - 1;
	}
};