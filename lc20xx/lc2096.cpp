//--- Q: 2096. Step-By-Step Directions From a Binary Tree Node to Another

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//--- method 1: lca + tracing path
class Solution {
public:
    string startpath = "", endpath = "";
    string getDirections(TreeNode* root, int startValue, int destValue) {
        auto node = postorder(root, startValue, destValue);
        string path;
        path = "";
        findstart(node, path, startValue);
        path = "";
        findend(node, path, destValue);
        return startpath+endpath;
    }
    TreeNode *postorder(TreeNode *root, int startValue, int destValue) {
        if (!root || root->val == startValue || root->val == destValue) {
            return root;
        }
        auto lv = postorder(root->left, startValue, destValue);
        auto rv = postorder(root->right, startValue, destValue);
        if (lv && rv) {
            return root;
        } else if (lv) {
            return lv;
        } else {
            return rv;
        }
    }
    void findstart(TreeNode *root, string &path, int val) {
        if (root->val == val) {
            startpath = path;
            return;
        }
        path += 'U';
        if (root->left) {
            findstart(root->left, path, val);
        }
        if (root->right) {
            findstart(root->right, path, val);
        }
        path.pop_back();
    }
    void findend(TreeNode *root, string &path, int val) {
        if (root->val == val) {
            endpath = path;
            return;
        }
        if (root->left) {
            path += 'L';
            findend(root->left, path, val);
            path.pop_back();
        }
        if (root->right) {
            path += 'R';
            findend(root->right, path, val);
            path.pop_back();
        }
    }
};

//--- method 2: backtracking
class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string startpath = "", destpath = "";
        postorder(root, startValue, startpath);
        postorder(root, destValue, destpath);
        while (startpath.size() && destpath.size() && startpath.back() == destpath.back()) {
            startpath.pop_back();
            destpath.pop_back();
        }
        return string(startpath.size(), 'U') + string(rbegin(destpath), rend(destpath));
    }
    bool postorder(TreeNode *root, int val, string &path) {
        if (root->val == val) {
            return true;
        }
        if (root->left && postorder(root->left, val, path)) {
            path += 'L';
            return path.size();
        }
        if (root->right && postorder(root->right, val, path)) {
            path += 'R';
            return path.size();
        }
        return false;
    }
};