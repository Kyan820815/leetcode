//--- Q: 315. Count of Smaller Numbers After Self

//--- method 1: O(nlogn) divide & conquer
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(n, 0), idx;
        for (int i = 0; i < n; ++i) {
            idx.push_back(i);
        }
        divide(0, n-1, idx, nums, cnt);
        return cnt;
    }
    void divide(int start, int end, vector<int> &idx, vector<int> &nums, vector<int> &cnt) { 
        if (start < end) {
            int mid = (end - start) / 2 + start;
            divide(start, mid, idx, nums, cnt);
            divide(mid+1, end, idx, nums, cnt);
            conquer(start, mid, end, idx, nums, cnt);
        }
    }
    void conquer(int start, int mid, int end, vector<int> &idx, vector<int> &nums, vector<int> &cnt) { 
        int i = start, j = mid+1;
        int lower = 0;
        vector<int> cp_idx;
        while (i <= mid && j <= end) {
            if (nums[idx[i]] > nums[idx[j]]) {
                cp_idx.push_back(idx[j++]);
                ++lower;
            } else {
                cnt[idx[i]] += lower;
                cp_idx.push_back(idx[i++]);
            }
        }
        while (i <= mid) {
            cnt[idx[i]] += lower;
            cp_idx.push_back(idx[i++]);
        }
        while (j <= end) {
            cp_idx.push_back(idx[j++]);
        }
        for (int i = start; i <= end; ++i) {
            idx[i] = cp_idx[i-start];
        }
    }
};