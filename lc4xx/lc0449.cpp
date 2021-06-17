//--- Q: 449. Serialize and Deserialize BST

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: preorder solution (dfs)
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res, lres = "", rres = "";
        if (!root) return " ";
        res = to_string(root->val);
        if (root->left)
        	lres = serialize(root->left);
        if (root->right)
        	rres = serialize(root->right);
        res = res + " " + lres + " " + rres;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    	TreeNode *root = NULL, *cur;
    	vector<TreeNode *> sk;
    	istringstream istr(data);
    	string s;
    	while (istr >> s)
    	{
    		int val = stoi(s);
    		TreeNode *last = NULL, *cur = new TreeNode(val);
    		while (sk.size() && sk.back()->val < val)
    		{
    			last = sk.back();
    			sk.pop_back();
    		}
    		if (last) 
    			last->right = cur;
    		else if (sk.size())
    			sk.back()->left = cur;
    		if (!root) root = cur;
    		sk.push_back(cur);
    	}
    	return root;
    }
};

//--- method 2: ostringstream, better
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        ostringstream ostr;
	    serialize(root, ostr);
        return ostr.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    	TreeNode *root = NULL, *cur;
    	vector<TreeNode *> sk;
    	istringstream istr(data);
    	string s;
    	while (istr >> s)
    	{
    		int val = stoi(s);
    		TreeNode *last = NULL, *cur = new TreeNode(val);
    		while (sk.size() && sk.back()->val < val)
    		{
    			last = sk.back();
    			sk.pop_back();
    		}
    		if (last) 
    			last->right = cur;
    		else if (sk.size())
    			sk.back()->left = cur;
    		if (!root) root = cur;
    		sk.push_back(cur);
    	}
    	return root;
    }

    void serialize(TreeNode *root, ostringstream &ostr)
    {
		ostr << root->val << " ";
		if (root->left)
			serialize(root->left, ostr);
		if (root->right)
			serialize(root->right, ostr);
    }
};

//--- method 3: use bst
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
        ss << " " + to_string(root->val);
        encode(root->left, ss);
        encode(root->right, ss);
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream ss(data);
        string str;
        while (ss >> str) {
            que.push(stoi(str));
        }
        if (!que.size()) {
            return NULL;
        }
        return decode(INT_MIN, INT_MAX);
    }
    TreeNode *decode(int minv, int maxv) {
        if (!que.size() || que.front() <= minv || que.front() >= maxv) {
            return NULL;
        }
        auto now = new TreeNode(que.front());
        que.pop();
        now->left = decode(minv, now->val);
        now->right = decode(now->val, maxv);
        return now;
    }
    queue<int> que;
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));