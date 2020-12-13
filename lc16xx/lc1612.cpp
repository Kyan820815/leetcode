//--- Q: 1612. Check If Two Expression Trees are Equivalent

/**
 * Definition for a binary tree node.
 * struct Node {
 *     char val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(' '), left(nullptr), right(nullptr) {}
 *     Node(char x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
 * };
 */

//--- method 1: preorder
class Solution {
public:
    vector<int> cnt;
    bool checkEquivalence(Node* root1, Node* root2) {
        cnt.resize(26, 0);
        preorder(root1, 1);
        preorder(root2, -1);
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] < 0) {
                return false;
            }
        }
        return true;
    }
    void preorder(Node *root, int dir) {
        if (!root->left && !root->right) {
            cnt[root->val-'a'] += dir;
        }
        if (root->left) {
            preorder(root->left, dir);
        }
        if (root->right) {
            preorder(root->right, dir);
        }
    }
};

//--- follow up: internal node has '-'
class Solution {
public:
    vector<int> cnt;
    bool checkEquivalence(Node* root1, Node* root2) {
        cnt.resize(26, 0);
        preorder(root1, 1);
        preorder(root2, -1);
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] < 0) {
                return false;
            }
        }
        return true;
    }
    void preorder(Node *root, int dir) {
        if (!root->left && !root->right) {
            cnt[root->val-'a'] += dir;
        }
        if (root->left) {
            preorder(root->left, dir);
        }
        if (root->right) {
            dir = (root->val == '-') ? -dir : dir;
            preorder(root->right, dir);
        }
    }
};