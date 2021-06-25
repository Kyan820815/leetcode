//--- Q: 559. Maximum Depth of N-ary Tree

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

//--- method 1: postorder traversel
class Solution {
public:
    int maxDepth(Node* root) {
    	if (!root) return 0;
    	int max_depth = 0;
		for (int i = 0; i < root->children.size(); ++i)
		{
			int depth = maxDepth(root->children[i]);
			if (max_depth < depth)
				max_depth = depth;
		}
		return max_depth+1;
    }
};