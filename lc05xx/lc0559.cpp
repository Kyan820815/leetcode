//--- Q: 0559. Maximum Depth of N-ary Tree

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
        if (!root) {
            return 0;
        }
        return postorder(root);
    }
    int postorder(Node *root) {
        int maxd = 0;
        for (auto &child: root->children) {
            maxd = max(maxd, postorder(child));
        }
        return maxd+1;
    }
};