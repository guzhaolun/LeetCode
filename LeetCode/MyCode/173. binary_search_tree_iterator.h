#include <iostream>
#include <stack>
#include <queue>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class BSTIterator {
private:
	TreeNode* root;
	queue<TreeNode*> stacks;
	stack<TreeNode*> temp;
public:
	BSTIterator(TreeNode *root) {
		this->root = root;
		while (1)
		{
			while (root)
			{
				temp.push(root);
				root = root->left;
			}
			if (temp.empty())
				break;
			root = temp.top();
			stacks.push(root);
			temp.pop();
			root = root->right;
		}
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !stacks.empty();
	}

	/** @return the next smallest number */
	int next() {
		TreeNode* t = stacks.front();
		stacks.pop();
		return t->val;
	}
};

/**
* Your BSTIterator will be called like this:
* BSTIterator i = BSTIterator(root);
* while (i.hasNext()) cout << i.next();
*/