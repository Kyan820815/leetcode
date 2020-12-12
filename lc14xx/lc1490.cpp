//--- Q: 1490. Clone N-ary Tree

//--- method 1: preorder
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    Node* cloneTree(Node* root) {
        if (!root) {
            return NULL;
        }
        Node *cpy = new Node(root->val);
        for (int i = 0; i < root->children.size(); ++i) {
            cpy->children.push_back(cloneTree(root->children[i]));
        }
        return cpy;
    }
};