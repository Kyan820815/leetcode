//--- Q: 307. Range Sum Query - Mutable

//--- method 1: segement tree
class Node {
public:
    int start, end, sum;
    Node *left, *right;
    Node() {
        start = end = sum = 0;
        left = right = NULL;
    }
};
class SegTree {
public:
    SegTree(vector<int> &nums) {
        if (!nums.size()) {
            root = NULL;
        } else {
            root = BuildTree(nums, 0, nums.size()-1);
        }
    }
    Node *BuildTree(vector<int> &nums, int start, int end) {
        Node *root = new Node();
        root->start = start;
        root->end = end;
        if (start == end) {
            root->sum = nums[start];
            return root;
        }
        int mid = (end-start)/2 + start;
        root->left = BuildTree(nums, start, mid);
        root->right = BuildTree(nums, mid+1, end);
        root->sum = root->left->sum + root->right->sum;
        return root;
    }
    int UpdateTree(Node *root, int i, int val) {
        int diff;
        if (root->start == i && root->end == i) {
            diff = root->sum - val;
            root->sum = val;
        } else {
            int mid = (root->end-root->start) / 2 + root->start;
            if (mid >= i) {
                diff = UpdateTree(root->left, i, val);
            } else {
                diff = UpdateTree(root->right, i, val);
            }
            root->sum -= diff;
        }
        return diff;
    }
    void UpdateTree(int i, int val) {
        UpdateTree(root, i, val);
    }
    int QueryTree(Node *root, int i, int j) {
        if (root->start == i && root->end == j) {
            return root->sum;
        }
        int mid = (root->end-root->start) / 2 + root->start;
        if (mid >= j) {
            return QueryTree(root->left, i, j);
        } else if (i > mid) {
            return QueryTree(root->right, i, j);
        }
        return QueryTree(root->left, i, mid) + QueryTree(root->right, mid+1, j);
    }
    int QueryTree(int i, int j) {
        return QueryTree(root, i, j);
    }
private:
    Node *root;
};
class NumArray {
public:
    NumArray(vector<int>& nums) {
        segt = new SegTree(nums);
    }
    
    void update(int i, int val) {
       segt->UpdateTree(i, val);
    }
    
    int sumRange(int i, int j) {
       return segt->QueryTree(i, j);
    }
    SegTree *segt;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */