//--- Q: 431. Encode N-ary Tree to Binary Tree

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
            return NULL;
        }
        vector<Node *> same = {root};
        return encode_binary(same);
    }
    
    TreeNode *encode_binary(vector<Node *> &same) {
        Node *root = NULL;
        TreeNode *dummy = new TreeNode(-1), *cur = dummy;
        for (int i = 0; i < same.size(); ++i) {
            cur->right = new TreeNode(same[i]->val);
            cur = cur->right;
            cur->left = encode_binary(same[i]->children);
        }
        return dummy->right;
    }
    
    // Decodes your binary tree to an n-ary tree.
    Node *decode(TreeNode* root) {
        if (!root) {
            return NULL;
        }
        vector<Node *> rtn = decode_nary(root);
        return rtn[0];
    }
    
    vector<Node *> decode_nary(TreeNode* root) {
        vector<Node *> rtn;
        while (root) {
            Node *now = new Node(root->val);
            if (root->left) {
                now->children = decode_nary(root->left);
            }
            rtn.push_back(now);
            root = root->right;
        }
        return rtn;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));