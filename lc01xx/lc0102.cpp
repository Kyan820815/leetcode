//--- Q: 102. Binary Tree Level Order Traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- mehtod 1: dfs (preorder), better cuz more clean
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
    	vector<vector<int>> out;
        preorder(root, 0, out);
    	return out;
    }
    void preorder(TreeNode* root, int level, vector<vector<int>> &out)
    {
    	if (root != NULL)
    	{
    		if (out.size() <= level)
    			out.push_back({root->val});
    		else
    			out[level].push_back(root->val);
    		preorder(root->left, level+1, out);
    		preorder(root->right, level+1, out);
    	}	
    }
};

//--- method 2: bfs
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
    	vector<vector<int>> out;
        bfs(root, out);
    	return out;
    }
    void bfs(TreeNode* root, vector<vector<int>> &out)
    {
        int q_size = 1;
        queue<TreeNode*> que;
        std::vector<int> row;

        if (root == NULL) return;
        que.push(root);
    	while(!que.empty())
    	{
            if (que.front()->left)
                que.push(que.front()->left);
            if (que.front()->right)
                que.push(que.front()->right);
            row.push_back(que.front()->val);
            que.pop();
            if (--q_size == 0)
            {
                out.push_back(row);
                row.clear();
                q_size = que.size();
            }
    	}
    }
};