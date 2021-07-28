//--- Q: 0449. Serialize and Deserialize BST

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: sstream lib with bst
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream ss;
        encode(root, ss);
        return ss.str();
    }

    void encode(TreeNode *root, ostringstream &ss) {
        if (!root) {
            return;
        }
        ss << to_string(root->val) + " ";
        encode(root->left, ss);
        encode(root->right, ss);
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream ss(data);
        queue<int> que;
        string str;
        while (ss >> str) {
            que.push(stoi(str));
        }
        return decode(que, INT_MIN, INT_MAX);
    }
    
    TreeNode *decode(queue<int> &que, int minv, int maxv) {
        if (!que.size() || que.front() >= maxv || que.front() <= minv) {
            return nullptr;
        }
        auto now = new TreeNode(que.front());
        que.pop();
        now->left = decode(que, minv, now->val);
        now->right = decode(que, now->val, maxv);
        return now;
    }
};

//--- method 2: stack iteration for construct tree given string
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "";
        }
        return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream ss(data);
        vector<TreeNode *> sk;
        string str;
        TreeNode *root = nullptr;
        while (ss >> str) {
            TreeNode *last = nullptr;
            while (sk.size() && sk.back()->val < stoi(str)) {
                last = sk.back();
                sk.pop_back();
            }
            auto now = new TreeNode(stoi(str));
            if (!root) {
                root = now;
            }
            if (last) {
                last->right = now;
            } else if (sk.size()) {
                sk.back()->left = now;
            }
            sk.push_back(now);
        }
        return root;
    }
};



// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));