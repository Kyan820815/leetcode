//--- Q: 0307. Range Sum Query - Mutable

//--- method 1: segement tree
class TNode {
public:
    TNode(int s, int e) {
        left = right = nullptr;        
        start = s, end = e;
    }
    TNode *left, *right;
    int val, start, end;
};

class NumArray {
public:
    TNode *root;    
    
    NumArray(vector<int>& nums) {
        root = buildTree(0, nums.size()-1, nums);
    }
    
    TNode *buildTree(int start, int end, vector<int> &nums) {
        auto cur = new TNode(start, end);
        if (start == end) {
            cur->val = nums[start];
        } else {
            int mid = start + (end-start)/2;
            cur->left = buildTree(start, mid, nums);
            cur->right = buildTree(mid+1, end, nums);
            cur->val = cur->left->val + cur->right->val;
        }
        return cur;
    }
    
    int update(int index, int val, TNode *cur) {
        int diff;
        if (cur->start == index && cur->end == index) {
            diff = cur->val-val;
            cur->val = val;
        } else {
            int mid = cur->start + (cur->end-cur->start)/2;
            if (mid < index) {
                diff = update(index, val, cur->right);
            } else {
                diff = update(index, val, cur->left);
            }
            cur->val -= diff;
        }
        return diff;
    }
    
    void update(int index, int val) {
        update(index, val, root);
    }
    
    int query(int left, int right, TNode *cur) {
        if (cur->start == left && cur->end == right) {
            return cur->val;
        }
        int mid = cur->start + (cur->end-cur->start)/2;
        if (right <= mid) {
            return query(left, right, cur->left);
        } else if (left > mid) {
            return query(left, right, cur->right);
        } else {
            return query(left, mid, cur->left) + query(mid+1, right, cur->right);
        }
    }
    
    int sumRange(int left, int right) {
        return query(left, right, root);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */