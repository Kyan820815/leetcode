//--- Q: 0493. Reverse Pairs

//--- method 1: divide & conquer
class Solution {
public:
    int res = 0;
    int reversePairs(vector<int>& nums) {
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
        int i, j, l;
        vector<int> cpy;
        for (i = start, l = start, j = mid+1; j <= end; ++j) {
            for (; i <= mid && nums[i] < nums[j]; ++i) {
                cpy.push_back(nums[i]);
            }
            for (; l <= mid && (double)nums[l]/2 <= (double)nums[j]; ++l);
            res += mid-l+1;
            cpy.push_back(nums[j]);
        }
        for (; i <= mid; ++i) {
            cpy.push_back(nums[i]);
        }
        for (int i = start; i <= end; ++i) {
            nums[i] = cpy[i-start];
        }
    }
};

//--- method 2: segment tree
class TNode {
public:
    TNode(int st, int ed) {
        cnt = 0;
        start = st, end = ed;
        left = right = nullptr;
    }
    int start, end, cnt;
    TNode *left, *right;
};

class SegTree {
public:
    SegTree(int start, int end, int cnt) {
        root = buildTree(start, end, 0);
    }
    TNode *buildTree(int start, int end, int cnt) {
        auto now = new TNode(start, end);
        if (start < end) {
            int mid = start + (end-start)/2;
            now->left = buildTree(start, mid, cnt);
            now->right = buildTree(mid+1, end, cnt);
            now->cnt = now->left->cnt + now->right->cnt;
        } else if (start == end) {
            now->cnt = cnt;     
        }
        return now;
    }
    void update(int idx, TNode *root) {
        if (!root) {
            return;
        }
        if (idx > root->end || idx < root->start) {
            return;
        }
        if (root->start <= idx && idx <= root->end) {
            ++root->cnt;
        }
        update(idx, root->left);
        update(idx, root->right);
    }
    void update(int idx) {
        update(idx, root);
    }
    int query(int start, int end, TNode *root) {
        if (!root) {
            return 0;
        }
        if (start == root->start && end == root->end) {
            return root->cnt;
        }
        int mid = root->start + (root->end-root->start)/2;
        if (start > mid) {
            return query(start, end, root->right);
        } else if (end <= mid) {
            return query(start, end, root->left);
        } else {
            return query(start, mid, root->left) + query(mid+1, end, root->right);
        }
    }
    int query(int start, int end) {
        return query(start, end, root);
    }
    TNode *root;
};

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        vector<double> sorted_nums;
        for (auto &num: nums) {
            sorted_nums.push_back(num);
            sorted_nums.push_back((double)num/2);
        }
        unordered_map<double, int> map;
        sort(sorted_nums.begin(), sorted_nums.end());
        for (int i = 0; i < sorted_nums.size(); ++i) {
            map[sorted_nums[i]] = i+1;
        }
        SegTree *data = new SegTree(0, sorted_nums.size()-1, 0);
        int res = 0;
        for (int i = nums.size()-1; i >= 0; --i) {
            auto idx = map[nums[i]];
            auto qidx = (abs(nums[i])%2 == 1) ? map[(double)nums[i]/2] : map[(double)nums[i]/2]-1;
            res += data->query(0, qidx);
            data->update(idx);

        }
        return res;
    }
};