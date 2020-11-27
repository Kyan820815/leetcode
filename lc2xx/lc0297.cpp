//--- Q: 297. Serialize and Deserialize Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: 
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
    	ostringstream ostr;
    	serialize(root, ostr);
    	return ostr.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    	istringstream istr(data);
        return deserialize(istr);
    }

    void serialize(TreeNode *root, ostringstream &ostr)
    {
    	if (!root)
    		ostr << "# ";
        else
        {
            ostr << root->val << " ";
            serialize(root->left, ostr);
            serialize(root->right, ostr);
        }
    }

    TreeNode *deserialize(istringstream &istr)
    {
    	string val;
    	istr >> val;
    	if (val == "#") return NULL;
    	TreeNode *root = new TreeNode(stoi(val));
    	root->left = deserialize(istr);
    	root->right = deserialize(istr);
    	return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));