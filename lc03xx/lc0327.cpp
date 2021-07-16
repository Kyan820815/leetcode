//--- Q: 0327. Count of Range Sum

//--- method 1: divide & conquer
# define ll long long
class Solution {
public:
    int res = 0, lv, uv;
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        lv = lower, uv = upper;
        vector<ll> sum = {0};
        for (auto &num: nums) {
            sum.push_back(sum.back()+num);
        }
        divide(0, sum.size()-1, sum);
        return res;
    }
    void divide(int start, int end, vector<ll> &sum) {
        if (start < end) {
            int mid = start + (end-start)/2;
            divide(start, mid, sum);
            divide(mid+1, end, sum);
            conquer(start, mid, end, sum);
        }
    }
    void conquer(int start, int mid, int end, vector<ll> &sum) {
        int i, j, l, u;
        vector<ll> cpy;
        for (i = start, j = mid+1, l = mid+1, u = mid+1; i <= mid; ++i) {
            for (; l <= end && sum[l]-sum[i] < lv; ++l);
            for (; u <= end && sum[u]-sum[i] <= uv; ++u);
            for (; j <= end && sum[j] < sum[i]; ++j) {
                cpy.push_back(sum[j]);
            }
            cpy.push_back(sum[i]);
            res += u-l;
        }
        for (; j<=end; ++j) {
            cpy.push_back(sum[j]);
        }
        for (int i = start; i <= end; ++i) {
            sum[i] = cpy[i-start];
        }
    }
};

//--- method 2: segment tree with range in minv, maxv
#define ll long long
class TNode {
public:
    TNode(ll st, ll ed) {
        left = right = nullptr;
        start = st, end = ed;
    }
    ll start, end;
    int cnt;
    TNode *left, *right;
};

class SegTree {
public:
    TNode *root;
    SegTree(ll start, ll end) {
        root = buildTree(start, end);
    }
    TNode *buildTree(ll start, ll end) {
        auto now = new TNode(start, end);
        if (start == end) {
            now->cnt = 0;
        } else {
            ll mid = start + (end-start)/2;
            now->left = buildTree(start, mid);
            now->right = buildTree(mid+1, end);
            now->cnt = now->left->cnt + now->right->cnt;
        }
        return now;
    }
    int update(ll idx, int cnt, TNode *now) {
        int diff;
        if (now->start == idx && now->end == idx) {
            now->cnt += cnt;
            diff = -cnt;
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
        if (now->start == start && now->end == end) {
            return now->cnt;
        }
        int mid = now->start + (now->end-now->start)/2;
        if (start > mid) {
            return query(start, end, now->right);
        } else if (end <= mid) {
            return query(start, end, now->left);
        } else {
            return query(start, mid, now->left) + query(mid+1, end, now->right);
        }
    }
    int query(int start, int end) {
        return query(start, end, root);
    }
};

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int sum = 0, res = 0, minv = INT_MAX, maxv = INT_MIN;
        set<ll> set;
        set.insert(sum);
        minv = min(minv, sum);
        maxv = max(maxv, sum);
        for (auto &num: nums) {
            sum += num;
            minv = min(minv, sum);
            maxv = max(maxv, sum);
            set.insert(sum);
        }
        vector<ll> psum;
        for (auto &num: set) {
            psum.push_back(num);
        }
        sort(psum.begin(), psum.end());
        sum = 0;
        SegTree *seg = new SegTree(minv, maxv);
        for (int i = 0; i < nums.size(); ++i) {
            seg->update(sum, 1);
            sum += nums[i];
            // lower <= current_prefix_sum - previous_prefix_sum <= upper
            // current_prefix_sum-upper <= previous_prefix_sum <= current_prefix_sum-lower
            res += seg->query(max(sum-upper, minv), min(sum-lower, maxv));
        }
        return res;
    }
};

//--- method 3: segment tree with nums.size() nodes
# define ll long long
class TNode {
public:
    TNode(ll st, ll ed) {
        left = right = nullptr;
        start = st, end = ed;
    }
    ll start, end;
    int cnt;
    TNode *left, *right;
};

class SegTree {
public:
    TNode *root;
    SegTree(int start, int end, vector<ll> &arr) {
        root = buildTree(start, end, arr);
    }
    TNode *buildTree(int start, int end, vector<ll> &arr) {
        auto now = new TNode(arr[start], arr[end]);
        if (start == end) {
            now->cnt = 0;
        } else {
            int mid = start + (end-start)/2;
            now->left = buildTree(start, mid, arr);
            now->right = buildTree(mid+1, end, arr);
            now->cnt = now->left->cnt + now->right->cnt;
        }
        return now;
    }
    void update(int idx, int cnt, TNode *now) {
        if (!now) {
            return;
        }
        if (now->start <= idx && idx <= now->end) {
            now->cnt += cnt;
            update(idx, cnt, now->left);
            update(idx, cnt, now->right);
        }
    }
    void update(int idx, int cnt) {
        update(idx, cnt, root);
    }
    int query(ll start, ll end, TNode *now) {
        if (!now) {
            return 0;
        }
        if (now->end < start || now->start > end) {
            return 0;
        }
        if (now->start >= start && now->end <= end) {
            return now->cnt;
        }
        return query(start, end, now->left) + query(start, end, now->right);
    }
    int query(ll start, ll end) {
        return query(start, end, root);
    }
};

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        ll sum = 0;
        int res = 0;
        set<ll> set;
        set.insert(0);
        for (auto &num: nums) {
            sum += num;
            set.insert(sum);
        }
        vector<ll> psum;
        for (auto &num: set) {
            psum.push_back(num);
        }
        sort(psum.begin(), psum.end());
        sum = 0;
        SegTree *seg = new SegTree(0, psum.size()-1, psum);
        for (int i = 0; i < nums.size(); ++i) {
            seg->update(sum, 1);
            sum += nums[i];
            // lower <= current_prefix_sum - previous_prefix_sum <= upper
            // current_prefix_sum-upper <= previous_prefix_sum <= current_prefix_sum-lower
            res += seg->query(sum-upper, sum-lower);
        }
        return res;
    }
};