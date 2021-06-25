//--- Q: 589. N-ary Tree Preorder Traversal

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

//--- method 1: iterative solution
class Solution {
public:
    vector<int> preorder(Node* root) {
        stack<Node *> sk;
        vector<int> res;
        Node *cur = root;
        while (cur || sk.size())
        {
        	res.push_back(cur->val);
        	for (int i = cur->children.size()-1; i > 0; --i)
        		sk.push(cur->children[i]);
        	if (cur->children.size())
        		cur = cur->children[0];
        	else
        	{
        		if (sk.size())
        		{
        			cur = sk.top();
        			sk.pop();
        		}
                else cur = NULL;
        	}
        }
        return res;
    }
};