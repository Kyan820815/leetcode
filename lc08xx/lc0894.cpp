//--- Q: 0894. All Possible Full Binary Trees

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: dfs recursion
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        return dfs(0, n-1);
    }
    vector<TreeNode *> dfs(int start, int end) {
        if (start > end) {
            return {nullptr};
        } else if (start == end) {
            return {new TreeNode(0)};
        }
        int mid = start + (end-start)/2;
        vector<TreeNode *> res;
        for (int i = start+1; i <= mid; i+=2) {
            auto leftvec = dfs(start, i-1);
            auto rightvec = dfs(i+1, end);
            for (auto &leftnode: leftvec) {
                for (auto &rightnode: rightvec) {
                    TreeNode *root = new TreeNode(0);
                    root->left = leftnode;            
                    root->right = rightnode;
                    res.push_back(root);
                    if (i < mid) {
                        root = new TreeNode(0);
                        root->right = leftnode;
                        root->left = rightnode;
                        res.push_back(root);
                    }
                }
            }
        }
        return res;
    }
};

//--- method 2: iterative solution
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<vector<TreeNode *>> res(n+1);
        res[0] = {nullptr}, res[1] = {new TreeNode(0)};
        for (int i = 2; i <= n; ++i) {
            int mid = (i-1)/2;
            for (int j = 1; j <= mid; j += 2) {
                for (auto &leftnode: res[j]) {
                    for (auto &rightnode: res[i-j-1]) {
                        auto now = new TreeNode(0);
                        now->left = leftnode;
                        now->right = rightnode;
                        res[i].push_back(now);
                        if (j < mid) {
                            auto now = new TreeNode(0);
                            now->right = leftnode;
                            now->left = rightnode;
                            res[i].push_back(now);
                        }
                    }
                }
            }
        }
        return res[n];
    }
}