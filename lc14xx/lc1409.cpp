//--- Q: 1409. Queries on a Permutation With Key

//--- method 1: map with iterator list
class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        unordered_map<int, list<int>::iterator> map;
        list<int> l;
        vector<int> res;
        for (int i = m; i >=1 ; --i) {
            l.push_front(i);
            map[i] = l.begin();
        }
        for (int i = 0; i < queries.size(); ++i) {
            int idx = distance(l.begin(), map[queries[i]]);
            res.push_back(idx);
            l.erase(map[queries[i]]);
            l.push_front(queries[i]);
            map[queries[i]] = l.begin();
        }
        return res;
    }
};

//--- method 2: BIT
class BIT {
public:
    BIT(int n) {
        m = 2*n;
        bit_arr.resize(m+1, 0);
    }
    int getSum(int idx) {
        int val = 0;
        while (idx > 0) {
            val += bit_arr[idx];
            idx = idx - (idx & (-idx));
        }
        return val;
    }
    void update(int idx, int val) {
        while (idx <= m) {
            bit_arr[idx] += val;
            idx = idx + (idx & (-idx));
        }
    }
    vector<int> bit_arr;
    int m;
};

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        BIT *tree = new BIT(m);
        unordered_map<int, int> pos;
        vector<int> res;
        for (int i = 1; i <= m; ++i) {
            pos[i] = i+m;
            tree->update(i+m, 1);
        }
        int cur = m;
        for (int i = 0; i < queries.size(); ++i) {
            int idx = pos[queries[i]];
            res.push_back(tree->getSum(idx-1));
            tree->update(idx, -1);
            tree->update(cur, 1);
            pos[queries[i]] = cur--;
        }
        return res;
    }
};

//--- method 3: segment tree
class TreePoint {
public:
    TreePoint *left, *right;
    int val, start, end;
    TreePoint() {
        left = right = NULL;
        val = 0;
    }
};

class Seg {
public:
    TreePoint *root;
    Seg(vector<int> &arr) {
        root = buildTree(0, arr.size()-1, root, arr);
    }
    TreePoint *buildTree(int left, int right, TreePoint *root, vector<int> &arr) {
        root = new TreePoint();
        root->start = left;
        root->end = right;
        if (left < right) {
            int mid = (right - left) / 2 + left;
            root->left = buildTree(left, mid, root->left, arr);
            root->right = buildTree(mid+1, right, root->right, arr);
            root->val = root->left->val + root->right->val;
        } else {
            root->val = arr[left];
        }
        return root;
    }
    int query(int left, int right, TreePoint *root) {
        if (root->start == left && root->end == right) {
            return root->val;
        }
        int mid = (root->end - root->start) / 2 + root->start;
        if (right <= mid) {
            return query(left, right, root->left);
        } else if (left > mid) {
            return query(left, right, root->right);
        } else {
            return query(left, mid, root->left) + query(mid+1, right, root->right);
        }
    }
    int query(int left, int right) {
        return query(left, right, root);
    }
    int update(int idx, int val, TreePoint *root) {
        int diff;
        if (root->start == idx && root->end == idx) {
            diff = root->val - val;
            root->val = val;
        } else {
            int mid = (root->end - root->start) / 2 + root->start;
            if (idx <= mid) {
                diff = update(idx, val, root->left);
            } else {
                diff = update(idx, val, root->right);
            }
            root->val -= diff;
        }
        return diff;
    }
    int update(int idx, int val) {
        return update(idx, val, root);
    }
};

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> arr(2*m+1, 0), res;
        unordered_map<int, int> record;
        for (int i = 1; i <= m; ++i) {
            arr[i+m] = 1;
            record[i] = i+m;
        }
        Seg *tree = new Seg(arr);
        for (int i = 0; i < queries.size(); ++i) {
            res.push_back(tree->query(0, record[queries[i]]-1));
            tree->update(record[queries[i]], 0);
            tree->update(m, 1);
            record[queries[i]] = m--;
        }
        return res;
    }
};
