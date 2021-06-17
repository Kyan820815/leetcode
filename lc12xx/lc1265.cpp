//--- Q: 1265. Print Immutable Linked List in Reverse

/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 * public:
 *    void printValue(); // print the value of the node.
 *    ImmutableListNode* getNext(); // return the next node.
 * };
 */


//--- method 1: O(n) time O(n) space
class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        if (!head) {
            return;
        }
        printLinkedListInReverse(head->getNext());
        head->printValue();
    }
};

//--- method 2: O(n^2) time O(1) space
class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        auto now = head;
        int len = 0;
        while (now) {
            ++len;
            now = now->getNext();
        }
        while (len) {
            auto tmp = head;
            int tmplen = len;
            while (--tmplen) {
                tmp = tmp->getNext();
            }
            tmp->printValue();
            --len;
        }
    }
};

//--- method 3: O(n) time O(sqrt(n)) space
class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        int len = 0;
        auto now = head;
        while (now) {
            now = now->getNext();
            ++len;
        }
        int blocksize = sqrt(len), cnt = 0;
        vector<ImmutableListNode *> sk;
        now = head;
        while (now) {
            if ((cnt++) % blocksize == 0) {
                sk.push_back(now);
            }
            now = now->getNext();
        }
        sk.push_back(NULL);
        for (int i = sk.size()-2; i >= 0; --i) {
            vector<ImmutableListNode *> tmpsk;
            auto cur = sk[i];
            while (cur != sk[i+1]) {
                tmpsk.push_back(cur);
                cur = cur->getNext();
            }
            while (tmpsk.size()) {
                tmpsk.back()->printValue();
                tmpsk.pop_back();
            }
        }
    }
};