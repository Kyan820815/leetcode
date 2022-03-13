//--- Q: 2179. Count Good Triplets in an Array

//--- method 1: segment tree
class TNode {
public:
    TNode() {
        left = right = nullptr;
    }
    int start, end, val;
    TNode *left, *right;
};

class SegTree {
public:
    TNode *root;
    SegTree(int start, int end) {
        root = buildTree(start, end);
    }
    TNode *buildTree(int start, int end) {
        TNode *now = new TNode();
        now->start = start, now->end = end;
        now->val = 0;
        if (start < end) {
            int mid = start + (end-start)/2;
            now->left = buildTree(start, mid);
            now->right = buildTree(mid+1, end);
        }
        return now;
    }
    int update(TNode *root, int idx, int val) {
        int diff;
        if (root->start == idx && root->end == idx) {
            diff = root->val-val;
            root->val = val;
        } else {
            int mid = root->start + (root->end-root->start)/2;
            if (mid < idx) {
                diff = update(root->right, idx, val);
            } else {
                diff = update(root->left, idx, val);
            }
            root->val -= diff;
        }
        return diff;
    }
    void update(int idx, int val) {
        update(root, idx, val);
    }
    int query(TNode *root, int start, int end) {
        if (root->start == start && root->end == end) {
            return root->val;
        } else {
            int mid = root->start + (root->end-root->start)/2;
            if (mid < start) {
                return query(root->right, start, end);
            } else if (end <= mid) {
                return query(root->left, start, end);
            } else {
                return query(root->left, start, mid) + query(root->right, mid+1, end);
            }
        }
    }
    int query(int start, int end) {
        return query(root, start, end);
    }
};
    
class Solution {
public:
    using ll = long long;
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> posIn2(n);
        for (int i = 0; i < n; ++i) {
            posIn2[nums2[i]] = i;
        }
        SegTree *seg1 = new SegTree(0, n), *seg2 = new SegTree(0, n);
        vector<int> pre, suf;
        for (int i = 0; i < n; ++i) {
            int pos = posIn2[nums1[i]];
            int tpos = pos+1;
            seg1->update(tpos, 1);
            pre.push_back(seg1->query(0, tpos-1));  
        }
        for (int i = n-1; i >= 0; --i) {
            int pos = posIn2[nums1[i]];
            int tpos = (n-pos-1)+1;
            seg2->update(tpos, 1);
            suf.push_back(seg2->query(0, tpos-1));
        }
        reverse(suf.begin(), suf.end());
        ll res = 0;
        for (int i = 0; i < n; ++i) {
            res += (ll)pre[i]*suf[i];
        }
        return res;
    }
};