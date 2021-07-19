//--- Q: 0707. Design Linked List

//--- method 1: dummy and linear finding index node
class TNode {
public:
    TNode(int v) {
        next = NULL;
        val = v;
    }
    TNode *next;
    int val;
};

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        sz = 0;
        dummy = new TNode(-1);
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    
    TNode *getNode(int index) {
        auto cur = dummy;
        for (int i = 0; i < index; ++i) {
            cur = cur->next;
        }
        return cur;
    }
    
    int get(int index) {
        if (index >= sz) {
            return -1;
        }
        return getNode(index)->next->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        addAtIndex(sz, val);
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > sz) {
            return;
        }
        TNode *node = new TNode(val);
        auto cur = getNode(index);
        auto tmp = cur->next;
        cur->next = node;
        node->next = tmp;
        ++sz;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index >= sz) {
            return;
        }
        --sz;
        auto cur = getNode(index);
        auto deleteNode = cur->next;
        cur->next = cur->next->next;
        delete(deleteNode);
    }
    int sz;
    TNode *dummy;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */