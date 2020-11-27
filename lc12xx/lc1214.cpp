//--- Q: 1214. Two Sum BSTs

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: stack operation
class Solution {
public:
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        stack<TreeNode *> sk1, sk2;
        TreeNode *now1 = root1, *now2 = root2;
        while (true) {
            while (now1) {
                sk1.push(now1);
                now1 = now1->left;
            }
            while (now2) {
                sk2.push(now2);
                now2 = now2->right;
            }
            if (!sk1.size() || !sk2.size())
                break;
            TreeNode *t1 = sk1.top();
            TreeNode *t2 = sk2.top();
            if (t1->val + t2->val < target) {
                now1 = t1->right;
                sk1.pop();
            } else if (t1->val + t2->val > target) {
                now2 = t2->left;
                sk2.pop();
            } else {
                return true;
            }
        }
        return false;
    }
};

//--- method 2: recursion
class Solution {
public:
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        return root2 && (find(root1, target-root2->val) || twoSumBSTs(root1, root2->left, target) 
                                                        || twoSumBSTs(root1, root2->right, target));
    }
    bool find(TreeNode *root, int t) {
        while (root) {
            if (root->val == t)
                return true;
            else if (root->val > t)
                root = root->left;
            else
                root = root->right;
        }
        return false;
    }
};