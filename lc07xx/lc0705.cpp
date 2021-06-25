//--- Q: 705. Design HashSet

//--- method 1: double array
class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        set.resize(1000);
    }
    
    void add(int key) {
        int pos = key/1000, hash = key%1000;
        if (!set[hash].size())
            set[hash].resize(1000 + (!hash ? 1 : 0), 0);
        set[hash][pos] = 1;
    }
    
    void remove(int key) {
        int pos = key/1000, hash = key%1000;
        if (set[hash].size())
            set[hash][pos] = 0;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int pos = key/1000, hash = key%1000;
        return (!set[hash].size() || !set[hash][pos]) ? false : true;
    }
    vector<vector<int>> set;
};

//--- method 2: array of list
class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        set.resize(1000);
    }
    
    void add(int key) {
        int hashv = h(key) % 1000;
        for (auto s = set[hashv].begin(); s != set[hashv].end(); ++s) {
            if (*s == key)
                return;
        }
        set[hashv].push_back(key);
    }
    
    void remove(int key) {
        int hashv = h(key) % 1000;
        for (auto s = set[hashv].begin(); s != set[hashv].end(); ++s) {
            if (*s == key) {
                set[hashv].erase(s);
                return;
            }
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int hashv = h(key) % 1000;
        for (auto s = set[hashv].begin(); s != set[hashv].end(); ++s) {
            if (*s == key) {
                return true;
            }
        }
        return false;
    }
    vector<list<int>> set;
    hash<int> h;
};

//--- method 3: bst
class Node {
public:
    Node (int value) {
        val = value;
        left = right = NULL;
    }
    
    ~Node () {
        if (left)
            delete left;
        if (right)
            delete right;
    }
    
    Node *left, *right;
    int val;
};

class BST {
public:
    BST() {
        root = NULL;
    }
    
    void insert(int key) {
        if (find(root, key))
            return;
        root = insert(root, key);
    }
    
    Node *insert(Node *root, int key) {
        if (!root)
            return new Node(key);
        if (root->val < key)
            root->right = insert(root->right, key);
        else if (root->val > key)
            root->left = insert(root->left, key);
        return root;
    }
    
    void remove(int key) {
        if (!find(root, key))
            return;
        root = remove(root, key);
    }
    
    Node *findMin(Node *root, Node **min) {
        if (root->left)
            root->left = findMin(root->left, min);
        else {
            Node *now = root->right;
            *min = root;
            return now;
        }
        return root;
    }
    
    Node *remove(Node *root, int key) {
        if (!root)
            return NULL;
        if (root->val < key)
            root->right = remove(root->right, key);
        else if (root->val > key)
            root->left = remove(root->left, key);
        else {
            Node *now;
            if (root->left && root->right) {
                Node *min = NULL;
                root->right = findMin(root->right, &min);
                min->right = root->right;
                min->left = root->left;
                root->left = root->right = NULL;
                delete root;
                return min;
            } else {
                now = root->left ? root->left : root->right;
                root->left = root->right = NULL;
                delete root;
            }
            return now;
        }
        return root;
    }
    
    bool find(int key) {
        return find(root, key);
    }
    
    bool find(Node *root, int key) {
        while (root) {
            if (root->val < key)
                root = root->right;
            else if (root->val > key)
                root = root->left;
            else
                return true;
        }
        return false;
    }
    
    Node *root;
};

class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        bst = new BST();
    }
    
    void add(int key) {
        bst->insert(key);
    }
    
    void remove(int key) {
        bst->remove(key);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return bst->find(key);
    }
    BST *bst;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */