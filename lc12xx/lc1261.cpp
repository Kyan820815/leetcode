//--- Q: 1261. Find Elements in a Contaminated Binary Tree

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

//--- method 1: use bit set
class FindElements {
public:
    FindElements(TreeNode* root) {
        dfs(root, 0);
    }
    
    bool find(int target) {
        return val[target];
    }
    void dfs(TreeNode *root, int now) {
        if (!root) {
            return;
        }
        val[now] = 1;
        dfs(root->left, 2*now+1);
        dfs(root->right, 2*now+2);
    }
    bitset<2<<20> val;
};

//--- method 2: use hash map
class FindElements {
public:
    FindElements(TreeNode* root) {
        dfs(root, 0);
    }
    
    bool find(int target) {
        return val.find(target) != val.end();
    }
    void dfs(TreeNode *root, int now) {
        if (!root) {
            return;
        }
        val.insert(now);
        dfs(root->left, 2*now+1);
        dfs(root->right, 2*now+2);
    }
    unordered_set<int> val;
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_
