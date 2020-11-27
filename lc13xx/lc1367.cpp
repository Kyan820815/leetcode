//--- Q: 1367. Linked List in Binary Tree

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

//--- method 1: check path fron current node
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) {
            return false;
        }
        return checkPath(head, root) || (isSubPath(head, root->left) || isSubPath(head, root->right));
    }
    bool checkPath(ListNode *head, TreeNode* root) {
        if (head == NULL) {
            return true;
        }
        if (!root) {
            return !head;
        }
        return head->val == root->val && (checkPath(head->next, root->left) || checkPath(head->next, root->right));
    }
};