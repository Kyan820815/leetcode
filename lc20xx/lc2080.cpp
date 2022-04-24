//--- Q: 2080. Range Frequency Queries

//--- method 1: binary search
class RangeFreqQuery {
public:
    unordered_map<int, vector<int>> map;
    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < arr.size(); ++i) {
            map[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        if (map.find(value) == map.end()) {
            return 0;
        }
        auto binarySearch = [&](int idx, int value) {
            int l = 0, r = map[value].size()-1;
            while (l < r) {
                int m = l + (r-l)/2;
                if (map[value][m] < idx) {
                    l = m+1;
                } else {
                    r = m;
                }
            }
            return l;
        };
        auto l = binarySearch(left, value);
        auto r = binarySearch(right, value);
        int resl = map[value][l] < left ? l+1 : l;
        int resr = map[value][r] > right ? r-1 : r;
        return resr-resl+1;
    }
};

//--- method 2: built in binary search
class RangeFreqQuery {
public:
    unordered_map<int, vector<int>> map;
    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < arr.size(); ++i) {
            map[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        if (map.find(value) == map.end()) {
            return 0;
        }
        auto liter = lower_bound(map[value].begin(), map[value].end(), left);
        auto riter = prev(upper_bound(map[value].begin(), map[value].end(), right));
        return riter-liter+1;
    }
};

//--- method 3: segment tree
class TNode {
public:
    TNode() {
        left = right = nullptr;
    }
    unordered_map<int,int> map;
    int start, end;
    TNode *left, *right;
};

class RangeFreqQuery {
public:
    TNode *root;
    RangeFreqQuery(vector<int>& arr) {
        root = buildTree(0, arr.size()-1, arr);
    }
    TNode *buildTree(int start, int end, vector<int> &arr) {
        TNode *now = new TNode();
        now->start = start, now->end = end;
        if (start < end) {
            int mid = start + (end-start)/2;
            now->left = buildTree(start, mid, arr);
            now->right = buildTree(mid+1, end, arr);
            now->map = now->left->map;
            for (auto &[val, cnt]: now->right->map) {
                now->map[val] += cnt;
            }
        } else {
            ++(now->map[arr[start]]);
        }
        return now;
    }
    int query(int left, int right, int value, TNode *root) {
        if (root->map.find(value) == root->map.end()) {
            return 0;
        }
        if (root->start == left && root->end == right) {
            return root->map[value];
        }
        int mid = root->start + (root->end-root->start)/2;
        if (left > mid) {
            return query(left, right, value, root->right);
        } else if (right <= mid) {
            return query(left, right, value, root->left);
        } else {
            return query(left, mid, value, root->left) + query(mid+1, right, value, root->right);
        }
    }
    int query(int left, int right, int value) {
        return query(left, right, value, root);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */