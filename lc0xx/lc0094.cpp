//--- Q: 094. Binary Tree Inorder Traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: inorder recursion
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> out;
        if (!root) return out;
        inorder(root, out);
        return out;
    }
    void inorder(TreeNode* root, vector<int> &out)
    {
    	if (root->left) inorder(root->left, out);
    	out.push_back(root->val);
    	if (root->right) inorder(root->right, out);
    }
};

//--- method 2: iterative solution using stack
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> out;
        inorder(root, out);
        return out;
    }
    void inorder(TreeNode* root, vector<int> &out)
    {
        stack<TreeNode*> sk;
        TreeNode *cur;
        cur = root;
        while (cur || !sk.empty())
        {
            while(cur)
            {
                sk.push(cur);
                cur = cur->left;
            }
            cur = sk.top();
            sk.pop();
            out.push_back(cur->val);
            cur = cur->right;
        }
    }
};

//--- method 3: morris travesal
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> out;
        inorder(root, out);
        return out;
    }
    void inorder(TreeNode* root, vector<int> &out)
    {
        TreeNode *cur, *prev;
        cur = root;
        while (cur)
        {
            if (cur->left)
            {
                prev = cur;
                cur = cur->left;
                while (cur->right && cur->right != prev) cur = cur->right;
                if (!cur->right)
                {
                    cur->right = prev;
                    cur = prev->left;
                }
                else 
                {
                    cur->right = NULL;
                    out.push_back(prev->val);
                    cur = prev->right;
                }
            }
            else
            {
                out.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
};