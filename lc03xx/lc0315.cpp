//--- Q: 315. Count of Smaller Numbers After Self

//--- method 1: O(nlogn) divide & conquer
class Solution {
public:
    vector<int> idx, res;
    vector<int> countSmaller(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            idx.push_back(i);
        }
        res.resize(nums.size(), 0);
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
        int i = start, j = mid+1, lower = 0;
        vector<int> cpy;
        while (i <= mid) {
            while (j <= end && nums[idx[i]] > nums[idx[j]]) {
                ++lower;
                cpy.push_back(idx[j++]);
            }
            res[idx[i]] += lower;
            cpy.push_back(idx[i++]);
        }
        while (j <= end) {
            cpy.push_back(idx[j++]);
        }
        for (int i = 0; i < cpy.size(); ++i) {
            idx[i+start] = cpy[i];
        }
    }
};