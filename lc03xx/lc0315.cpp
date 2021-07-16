//--- Q: 0315. Count of Smaller Numbers After Self

//--- method 1: O(nlogn) divide & conquer
class Solution {
public:
    vector<int> res, idx;
    vector<int> countSmaller(vector<int>& nums) {
        res.resize(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            idx.push_back(i);
        }
        divide(0, nums.size()-1, nums);
        return res;
    }
    void divide(int start, int end, vector<int> &nums) {
        if (start < end) {
            int mid = start + (end-start)/2;
            divide(start, mid, nums);
            divide(mid+1, end, nums);
            conquer(start, mid, end, nums);
        }
    }
    void conquer(int start, int mid, int end, vector<int> &nums) {
        vector<int> cpy;
        int i = start, j = mid+1, lower = 0;
        while (i <= mid && j <= end) {
            if (nums[idx[i]] <= nums[idx[j]]) {
                res[idx[i]] += lower;
                cpy.push_back(idx[i++]);
            } else {
                ++lower;
                cpy.push_back(idx[j++]);
            }
        }
        while (i <= mid) {
            res[idx[i]] += lower;
            cpy.push_back(idx[i++]);
        }
        while (j <= end) {
            cpy.push_back(idx[j++]);
        }
        for (int i = start; i <= end; ++i) {
            idx[i] = cpy[i-start];
        }
    }
};

//--- method 2: segment tree, construct tree with all values in minv and maxv
class TNode {
public:
    TNode (int st, int ed) {
        start = st, end = ed;
        left = right = nullptr;
    }
    int start, end, cnt;
    TNode *left, *right;
};

class SegTree {
public:
    TNode *root;
    SegTree(int start, int end, int cnt) {
        root = buildTree(start, end, cnt);
    }
    TNode *buildTree(int start, int end, int cnt) {
        auto now = new TNode(start, end);
        if (start == end) {
            now->cnt = cnt;
        } else {
            int mid = start + (end-start)/2;
            now->left = buildTree(start, mid, cnt);
            now->right = buildTree(mid+1, end, cnt);
            now->cnt = now->left->cnt + now->right->cnt;
        }
        return now;
    }
    int update(int idx, int cnt, TNode *now) {
        int diff;
        if (now->start == idx && now->end == idx) {
            diff = -cnt;
            now->cnt += cnt;
        } else {
            int mid = now->start + (now->end-now->start)/2;
            if (idx > mid) {
                diff = update(idx, cnt, now->right);
            } else {
                diff = update(idx, cnt, now->left);
            }
            now->cnt -= diff;
        }
        return diff;
    }
    void update(int idx, int cnt) {
        update(idx, cnt, root);
    }
    int query(int start, int end, TNode *now) {
        if (!now) {
            return 0;
        }
        if (start == now->start && end == now->end) {
            return now->cnt;
        } else {
            int mid = now->start + (now->end-now->start)/2;
            if (start > mid) {
                return query(start, end, now->right);
            } else if (end <= mid) {
                return query(start, end, now->left);
            } else {
                return query(start, mid, now->left) + query(mid+1, end, now->right);
            }
        }
    }
    int query(int start, int end) {
        return query(start, end, root);
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int minv = INT_MAX, maxv = INT_MIN;
        for (auto &num: nums) {
            minv = min(minv, num);
            maxv = max(maxv, num);
        }
        SegTree *seg = new SegTree(minv, maxv, 0);
        for (int i = nums.size()-1; i >= 0; --i) {
            seg->update(nums[i], 1);
            nums[i] = seg->query(minv, nums[i]-1);
        }
        return nums;
    }
};

//--- method 3: segment tree, construct tree with nums.size() + 1
class TNode {
public:
    TNode (int st, int ed) {
        start = st, end = ed;
        left = right = nullptr;
    }
    int start, end, cnt;
    TNode *left, *right;
};

class SegTree {
public:
    TNode *root;
    SegTree(int start, int end, int cnt) {
        root = buildTree(start, end, cnt);
    }
    TNode *buildTree(int start, int end, int cnt) {
        auto now = new TNode(start, end);
        if (start == end) {
            now->cnt = cnt;
        } else {
            int mid = start + (end-start)/2;
            now->left = buildTree(start, mid, cnt);
            now->right = buildTree(mid+1, end, cnt);
            now->cnt = now->left->cnt + now->right->cnt;
        }
        return now;
    }
    int update(int idx, int cnt, TNode *now) {
        int diff;
        if (now->start == idx && now->end == idx) {
            diff = -cnt;
            now->cnt += cnt;
        } else {
            int mid = now->start + (now->end-now->start)/2;
            if (idx > mid) {
                diff = update(idx, cnt, now->right);
            } else {
                diff = update(idx, cnt, now->left);
            }
            now->cnt -= diff;
        }
        return diff;
    }
    void update(int idx, int cnt) {
        update(idx, cnt, root);
    }
    int query(int start, int end, TNode *now) {
        if (start == now->start && end == now->end) {
            return now->cnt;
        } else {
            int mid = now->start + (now->end-now->start)/2;
            if (start > mid) {
                return query(start, end, now->right);
            } else if (end <= mid) {
                return query(start, end, now->left);
            } else {
                return query(start, mid, now->left) + query(mid+1, end, now->right);
            }
        }
    }
    int query(int start, int end) {
        return query(start, end, root);
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int minv = INT_MAX, maxv = INT_MIN;
        auto sort_nums = nums;
        sort(sort_nums.begin(), sort_nums.end());
        unordered_map<int, int> map;
        for (int i = 0; i < sort_nums.size(); ++i) {
            map[sort_nums[i]] = i+1;
        }
        SegTree *seg = new SegTree(0, nums.size(), 0);
        for (int i = nums.size()-1; i >= 0; --i) {
            auto idx = map[nums[i]];
            seg->update(idx, 1);
            nums[i] = seg->query(0, idx-1);
        }
        return nums;
    }
};