//--- Q: 1522. Diameter of N-Ary Tree

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

//--- method 1: postorder
class Solution {
public:
    int res = 0;
    int diameter(Node* root) {
        postorder(root);
        return res;
    }
    int postorder(Node *root) {
        if (!root) {
            return 0;
        }
        int first = 0, second = 0;
        for (int i = 0; i < root->children.size(); ++i) {
            int rtn = postorder(root->children[i]);
            if (first < rtn) {
                second = first;
                first = rtn;
            } else if (second < rtn) {
                second = rtn;
            }
        }
        res = max(res, second+first);
        return max(first, second)+1;
    }
};