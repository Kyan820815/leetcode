//--- Q: 0431. Encode N-ary Tree to Binary Tree

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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: left: children, rightL same level
class Codec {
public:
    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        if (!root) {
            return nullptr;
        }
        vector<Node *> sibs = {root};
        return encode1(sibs);
    }
    
    TreeNode *encode1(vector<Node *> &sibs) {
        auto dummy = new TreeNode(-1), now = dummy;
        for (auto &sib: sibs) {
            now->right = new TreeNode(sib->val);
            now = now->right;
            if (sib->children.size()) {
                now->left = encode1(sib->children);
            }
        }
        return dummy->right;
    }
    
    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
        auto sibs = decode1(root);
        return sibs.size() ? sibs[0] : nullptr;
    }
    
    vector<Node *> decode1(TreeNode *root) {
        vector<Node *> sibs;
        while (root) {
            auto now = new Node(root->val);
            sibs.push_back(now);
            if (root->left) {
                now->children = decode1(root->left);
            }
            root = root->right;
        }
        return sibs;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));