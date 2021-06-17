//--- Q: 173. Binary Search Tree Iterator

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: stack iteration
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        auto now = root;
        while (now) {
            sk.push_back(now);
            now = now->left;
        }
    }
    
    int next() {
        auto now = sk.back();
        sk.pop_back();
        int val = now->val;
        now = now->right;
        while (now) {
            sk.push_back(now);
            now = now->left;
        }
        return val;
    }
    
    bool hasNext() {
        return sk.size();
    }
    vector<TreeNode *> sk;
};

//--- method 2: moris traversal
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
    	p = root;
    }
    
    /** @return the next smallest number */
    int next() {
    	int val;
    	while(p)
    	{
	    	if (p->left)
	    	{
	    		TreeNode *pre = p;
	    		p = p->left;
	    		while (p->right != NULL && p->right != pre)
	    			p = p->right;
	    		if (p->right == NULL)
	    		{
	    			p->right = pre;
	    			p = pre->left;
	    		}
	    		else if (p->right == pre)
	    		{
	    			val = pre->val;
	    			p->right = NULL;
	    			p = pre->right;
	    			break;
	    		}
	    	}
	    	else
	    	{
	    		val = p->val;
	    		p = p->right;
	    		break;
	    	}
    	}

        return val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
		return (!p) ? false : true;        	
    }

private:
	TreeNode *p;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */