//--- Q: 2130. Maximum Twin Sum of a Linked List

//-- method 1: stack
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode *slow = head, *fast = head;
        vector<ListNode *> sk;
        while (fast && fast->next) {
            sk.push_back(slow);
            slow = slow->next;
            fast = fast->next->next;
        }
        int res = 0;
        while (sk.size()) {
            res = max(res, slow->val+sk.back()->val);
            sk.pop_back();
            slow = slow->next;
        }
        return res;
    }
};

//--- method 2: reverse
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *revH = nullptr, *cur = slow;
        while (cur) {
            auto tmp = cur->next;
            cur->next = revH;
            revH = cur;
            cur = tmp;
        }
        cur = head;
        int res = 0;
        while (cur && revH) {
            res = max(res, cur->val + revH->val);
            cur = cur->next;
            revH = revH->next;
        }
        return res;
    }
};