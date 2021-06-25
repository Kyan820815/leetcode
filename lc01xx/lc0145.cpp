//--- Q: 145. Binary Tree Postorder Traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: postorder recursion
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
     	vector<int> out;
     	if (!root) return out;
     	postorder(root, out);
     	return out;   
    }
    void postorder(TreeNode *root, vector<int> &out)
    {	
    	if (root->left) postorder(root->left, out);
    	if (root->right) postorder(root->right, out);
    	out.push_back(root->val);
    }
};

//--- method 2: iterative solution using stack
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
    	vector<int> out;
    	postorder(root, out);
    	return out;
    }
    void postorder(TreeNode *root, vector<int> &out)
    {
    	TreeNode *cur, *finish;
    	stack<TreeNode*> sk;
    	cur = root;
    	if (!cur) return;
    	sk.push(root);
    	while(!sk.empty())
    	{
    		cur = sk.top();
    		if (cur->left == finish || cur->right == finish || (!cur->left && !cur->right))
    		{
    			out.push_back(cur->val);
    			finish = cur;
    			sk.pop();
    		}
			else
			{
				if (cur->right) sk.push(cur->right);
				if(cur->left) sk.push(cur->left);
			}    		
    	}	
    }
};

//--- method 3: morris travesal
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> out;
        postorder(root, out);
        return out;
    }
    void postorder(TreeNode *root, vector<int> &out)
    {
    	TreeNode *sproot = new TreeNode(0);
        TreeNode *cur, *prev, *tmp;
        vector<int> tmpVec;

        sproot->left = root;
        cur = sproot;

        while(cur)
        {
            if (cur->left)
            {
                prev = cur;
                cur = cur->left;
                while(cur->right && cur->right != prev) cur = cur->right;
                
                if (!cur->right)
                {
                    cur->right = prev;
                    cur = prev->left;
                }
                else if (cur->right == prev)
                {
                    //--- back process from cur->right to prev->left
                    tmpVec.clear();
                    tmp = prev->left;
                    while(tmp != prev)
                    {
                        tmpVec.insert(tmpVec.begin(), tmp->val);
                        tmp = tmp->right;                        
                    }
                    out.insert(out.end(), tmpVec.begin(), tmpVec.end());
                    cur->right = NULL;
                    cur = prev->right;
                }
            }
            else
            {
                cur = cur->right;
            }
        }
    }
};