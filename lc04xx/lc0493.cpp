//--- Q: 493. Reverse Pairs

//--- method 1: divide & conquer
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        res = 0;
        divide(0, nums.size()-1, nums);
        return res;
    }
    void divide(int start, int end, vector<int> &nums) {
        if (start < end) {
            int mid = (end - start)/2 + start;
            divide(start, mid, nums);
            divide(mid+1, end, nums);
            conquer(start, mid, end, nums);
        }
    }
    void conquer(int start, int mid, int end, vector<int> &nums) {
        int i = start, t = mid+1, j = mid+1;
        vector<int> cp;
        while (i <= mid) {
            while (t <= end && (double)nums[i]/2 > nums[t]) {
                ++t;
            }
            while (j <= end && nums[i] > nums[j]) {
                cp.push_back(nums[j++]);
            }
            res += t-mid-1;
            cp.push_back(nums[i++]);
        }
        while (j <= end) {
            cp.push_back(nums[j++]);
        }
        for (int i = start; i <= end; ++i) {
            nums[i] = cp[i-start];
        }
    }
    int res;
};

//--- method 1-2: divide & conquer
class Solution {
public:
    int res = 0;
    int reversePairs(vector<int>& nums) {
        divide(0, nums.size()-1, nums);
        return res;
    }
    void divide(int start, int end, vector<int> &nums) {
        if (start < end) {
            int mid = start + (end-start) / 2;
            divide(start, mid, nums);
            divide(mid+1, end, nums);
            conquer(start, mid, end, nums);
        }
    }
    void conquer(int start, int mid , int end, vector<int> &nums) {
        vector<int> cp;
        int first = start, i = start;
        for (int j = mid+1; j <= end; ++j) {
            while (first <= mid && (double)nums[first]/2 <= nums[j]) {
                ++first;
            }
            res += (mid-first+1);
            while (i <= mid && nums[i] < nums[j]) {
                cp.push_back(nums[i++]);
            }
            cp.push_back(nums[j]);
        }
        while (i <= mid) {
            cp.push_back(nums[i++]);
        }
        for (int i = start; i <= end; ++i) {
            nums[i] = cp[i-start];
        }
    }
};