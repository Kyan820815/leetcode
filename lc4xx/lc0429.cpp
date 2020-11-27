//--- Q: 429. N-ary Tree Level Order Traversal

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

//--- method 1: preorder dfs
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (!root) return res;
        preorder(root, res, 0);
        return res;
    }
    void preorder(Node *root, vector<vector<int>> &res, int h)
    {
    	if (res.size() == h)
    		res.push_back({root->val});
    	else
    		res[h].push_back(root->val);
    	for (int i = 0; i < root->children.size(); ++i)
    		preorder(root->children[i], res, h+1);
    }
};

//--- method 2: bfs
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        queue<Node *> que;
        int qsize = 1;
        if (!root) return res;
        que.push(root);
        while (que.size())
        {
        	vector<int> res_vec;
        	for (int i = 0; i < qsize; ++i)
        	{
        		Node *now = que.front();
        		que.pop();
        		res_vec.push_back(now->val);
        		for (int j = 0; j < now->children.size(); ++j)
        			que.push(now->children[j]);
        	}
        	qsize = que.size();
        	res.push_back(res_vec);
        }
        return res;
    }
};