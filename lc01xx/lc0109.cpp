//--- Q: 0109. Convert Sorted List to Binary Search Tree
//--- last written: 2023/07/13

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: find mid and recursively find mid of left &right
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return dfs(head, nullptr);
    }
    TreeNode *dfs(ListNode *head, ListNode *end) {
        if (head == end) {
            return NULL;
        }
        auto slow = head, fast = head;
        while (fast != end && fast->next != end) {
            slow = slow->next;
            fast = fast->next->next;
        }
        auto right = slow->next;
        slow->next = NULL;
        auto now = new TreeNode(slow->val);
        now->left = dfs(head, slow);
        now->right = dfs(right, end);
        return now;
    }
};
