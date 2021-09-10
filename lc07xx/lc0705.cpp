//--- Q: 0705. Design HashSet

//--- method 1: array of list
class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        data.resize(1000);
    }
    
    void add(int key) {
        if (!contains(key)) {
            int pos = h(key)%1000;
            data[pos].push_back(key);
        }
    }
    
    void remove(int key) {
        int pos = h(key)%1000;
        for (auto it = data[pos].begin(); it != data[pos].end(); ++it) {
            if (*it == key) {
                data[pos].erase(it);
                break;
            }
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int pos = h(key)%1000;
        for (auto it = data[pos].begin(); it != data[pos].end(); ++it) {
            if (*it == key) {
                return true;
            }
        }
        return false;
    }
    vector<list<int>> data;
    hash<int> h;
};

//--- method 2: bst
class TNode {
public:
    TNode(int v) {
        val = v;
        left = right = nullptr;
    }
    int val;
    TNode *left, *right;
};

class BST {
public:
    BST() {
        dummy = new TNode(-1);
    }
    bool contains(int key) {
        auto root = dummy->left;
        while (root) {
            if (root->val < key) {
                root = root->right;
            } else if (root->val > key) {
                root = root->left;
            } else {
                return true;
            }
        }
        return false;
    }
    void add(int key) {
        TNode *p = dummy;
        auto root = dummy->left;
        int dir = 0;
        while (root) {
            if (root->val < key) {
                dir = 1;
                p = root;
                root = root->right;
            } else if (root->val > key) {
                dir = 0;
                p = root;
                root = root->left;
            } else {
                return;
            }
        }
        if (dir) {
            p->right = new TNode(key);
        } else {
            p->left = new TNode(key);
        }
    }
    TNode *findmin(TNode *node, TNode *p) {
        while (node->left) {
            p = node;
            node = node->left;
        }
        if (p->right == node) {
            p->right = node->right;
        } else {
            p->left = node->right;
        }
        return node;
    }
    void remove(int key) {
        TNode *p = dummy;
        auto root = dummy->left;
        int dir = 0;
        while (root) {
            if (root->val < key) {
                dir = 1;
                p = root;
                root = root->right;
            } else if (root->val > key) {
                dir = 0;
                p = root;
                root = root->left;
            } else {
                TNode *minnode;
                if (!root->left) {
                    minnode = root->right;
                } else if (!root->right) {
                    minnode = root->left;
                } else {
                    minnode = findmin(root->right, root);
                    minnode->left = root->left;
                    minnode->right = root->right;
                }
                if (dir) {
                    p->right = minnode;
                } else {
                    p->left = minnode;
                }
                break;
            }
        }
    }
    TNode *dummy;
};

class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        data = new BST();
    }
    
    void add(int key) {
        data->add(key);
    }
    
    void remove(int key) {
        data->remove(key);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return data->contains(key);
    }
    BST *data;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */