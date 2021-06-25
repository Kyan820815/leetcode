//--- Q: 109. Convert Sorted List to Binary Search Tree

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
        TreeNode *root = divide(head, NULL);
        return root;
    }
    TreeNode *divide(ListNode *head, ListNode *rear)
    {
    	TreeNode *node;
    	ListNode *slow, *fast;

    	fast = slow = head;
    	if (head == rear) return NULL;

    	while(fast != rear && fast->next != rear)
    	{
    		slow = slow->next;
    		fast = fast->next->next;
    	}
    	node = new TreeNode(slow->val);
    	node->left = divide(head, slow);
    	node->right = divide(slow->next, rear);
    	return node;
    }
};

//--- method 2: same with method 1 but using double pointer
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode ** root;
        root = (TreeNode **)malloc(sizeof(TreeNode *));
        divide(head, NULL, root);
        return *root;
    }
    void divide(ListNode *head, ListNode *rear, TreeNode **node)
    {
        ListNode *slow, *fast;

        fast = slow = head;
        if (head == rear)
        {
            *node = NULL;
            return;
        }

        while(fast != rear && fast->next != rear)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        *node = new TreeNode(slow->val);
        divide(head, slow, &(*node)->left);
        divide(slow->next, rear, &(*node)->right);
    }
};
