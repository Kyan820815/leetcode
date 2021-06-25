//--- Q: 103. Binary Tree Zigzag Level Order Traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: reverse vector without stl function
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> out;
        if (!root) return out;
        bfs(root, out);
        return out;
    }
    void bfs(TreeNode *root, vector<vector<int>> &out)
    {
        TreeNode *now;
        queue<TreeNode *> que;
        int dir = 1, qsize = 1, count = 1;
        vector<int> one_vec(qsize);
        que.push(root);
        while(!que.empty())
        {
            now = que.front();
            if (now->left)
                que.push(now->left);
            if (now->right)
                que.push(now->right);
            que.pop();

            if (dir == 1)
                one_vec[count-qsize] = now->val;
            else
                one_vec[qsize-1] = now->val;
            if (--qsize == 0)
            {
                out.push_back(one_vec);
                count = qsize = que.size();
                one_vec.resize(qsize);
                dir *= -1;
            }
        }
    }
};

//--- method 2: double stack without reverse vector
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> out;
        if (!root) return out;
        bfs(root, out);
        return out;
    }
    void bfs(TreeNode *root, vector<vector<int>> &out)
    {
    	TreeNode *now;
    	stack<TreeNode *> sk_now, sk_next;
    	int dir = 1;
    	vector<int> one_vec;

    	sk_now.push(root);
    	while(!sk_now.empty())
    	{
    		now = sk_now.top();
    		one_vec.push_back(now->val);
            if (dir == 1)
            {
                if (now->left)
                    sk_next.push(now->left);
                if (now->right)
                    sk_next.push(now->right);
            }
            else
            {
                if (now->right)
                    sk_next.push(now->right);
                if (now->left)
                    sk_next.push(now->left);
            }
    		sk_now.pop();
    		if (sk_now.empty())
    		{
    			out.push_back(one_vec);
    			one_vec.clear();
                sk_now = sk_next;
                stack<TreeNode*>().swap(sk_next);
    			dir *= -1;
    		}
    	}
    }
};

//--- method 3: reverse vector
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> out;
        if (!root) return out;
        bfs(root, out);
        return out;
    }
    void bfs(TreeNode *root, vector<vector<int>> &out)
    {
    	TreeNode *now;
    	queue<TreeNode *> que;
    	int dir = 1, qsize = 1;
    	vector<int> one_vec;
    	que.push(root);
    	while(!que.empty())
    	{
    		now = que.front();
    		one_vec.push_back(now->val);
    		if (now->left)
				que.push(now->left);
			if (now->right)
				que.push(now->right);
    		que.pop();
    		if (--qsize == 0)
    		{
    			if (dir == -1) reverse(one_vec.begin(), one_vec.end());
    			out.push_back(one_vec);
    			one_vec.clear();
    			qsize = que.size();
    			dir *= -1;
    		}
    	}
    }
};