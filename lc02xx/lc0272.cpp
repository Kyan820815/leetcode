//--- Q: 0272. Closest Binary Search Tree Value II

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

//--- method 1: two stack
class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<TreeNode *> left_sk, right_sk;
        TreeNode *now = root;
        while (now) {
            if (now->val < target) {
                left_sk.push_back(now);
                now = now->right;
            } else {
                right_sk.push_back(now);
                now = now->left;
            }
        }
        vector<int> res;
        for (; k; --k) {
            if (!left_sk.size()) {
                res.push_back(right_sk.back()->val);
                findleft(right_sk);
            } else if (!right_sk.size()) {
                res.push_back(left_sk.back()->val);
                findright(left_sk);
            } else {
                if (abs(target-left_sk.back()->val) < abs(target-right_sk.back()->val)) {
                    res.push_back(left_sk.back()->val);
                    findright(left_sk);
                } else {
                    res.push_back(right_sk.back()->val);
                    findleft(right_sk);
                }
            }
        }
        return res;
    }
    void findright(vector<TreeNode *> &sk) {
        auto now = sk.back();
        sk.pop_back();
        now = now->left;
        while (now) {
            sk.push_back(now);
            now = now->right;
        }
    }
    void findleft(vector<TreeNode *> &sk) {
        auto now = sk.back();
        sk.pop_back();
        now = now->right;
        while (now) {
            sk.push_back(now);
            now = now->left;
        }
        
    }
};

//--- method 2: inorder + binary search
class Solution {
public:
    vector<int> arr;
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        inorder(root);
        int left, right;
        for (left = 0, right = arr.size()-k; left < right;) {
            int mid = left + (right-left)/2;
            if (target-arr[mid] < arr[mid+k]-target) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return vector<int>(arr.begin()+left, arr.begin()+left+k);
    }
    void inorder(TreeNode *root) {
        if (root->left) {
            inorder(root->left);
        }
        arr.push_back(root->val);
        if (root->right) {
            inorder(root->right);
        }
    }
};
