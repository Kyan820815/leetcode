//--- Q: 590. N-ary Tree Postorder Traversal

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

//--- method 1: recursion
class Solution {
public:
    vector<int> postorder(Node* root) {
		vector<int> out;
		postorder(root, out);    
    	return out;
    }

    void postorder(Node* root, vector<int> &out)
    {
    	if (!root) return;
    	for (int i = 0; i < root->children.size(); ++i)
    		postorder(root->children[i], out);
    	out.push_back(root->val);
    }
};

//--- method 2: iterative stack
class Solution {
public:
    vector<int> postorder(Node* root) {
		vector<int> out;
		postorder(root, out);    
    	return out;
    }

    void postorder(Node* root, vector<int> &out)
    {
    	stack<Node *> sk;
    	Node *used, *now;
    	bool finished;

    	if (!root) return;

    	used = root;
    	sk.push(root);
    	while(!sk.empty())
    	{
    		now = sk.top();
    		finished = false;
    		for (int i = 0; i < now->children.size(); ++i)
    		{
    			if (now->children[i] == used)
    			{
    				finished = true;
    				break;
    			}
    		}
    		if (now->children.empty() || finished)
    		{
    			used = now;
    			out.push_back(now->val);
    			sk.pop();
    		}
    		else
    		{
    			for (int i = now->children.size()-1; i >= 0; --i)
	    			sk.push(now->children[i]);
    		}
    	}
    }
};

//--- method 3: inverse of preorder
class Solution {
public:
    vector<int> postorder(Node* root) {
		vector<int> out;
		postorder(root, out);    
    	return out;
    }

    void postorder(Node* root, vector<int> &out)
    {
    	stack<Node *> sk;
    	Node *now;

    	if (!root) return;
    	
    	sk.push(root);
    	while(!sk.empty())
    	{
    		now = sk.top();
    		sk.pop();
    		out.push_back(now->val);
    		for (int i = 0; i < now->children.size(); ++i)
    			sk.push(now->children[i]);
    	}
        reverse(out.begin(), out.end());
    }
};
