//--- Q: 0297. Serialize and Deserialize Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: c++ sstream library
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
            ss << " #";
        } else {
            ss << " " + to_string(root->val);
            encode(root->left, ss);
            encode(root->right, ss);
        }
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream ss(data);
        return decode(ss);
    }
    
    TreeNode *decode(istringstream &ss) {
        string str;
        ss >> str;
        if (str == "#") {
            return nullptr;
        }
        auto now = new TreeNode(stoi(str));
        now->left = decode(ss);
        now->right = decode(ss);
        return now;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));