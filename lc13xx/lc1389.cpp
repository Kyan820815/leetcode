//--- Q: 1389. Create Target Array in the Given Order

//--- method 1: divide & conquer
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        divide(0, nums.size()-1, nums, index);
        return nums;
    }
    void divide(int start, int end, vector<int> &nums, vector<int> &index) {
        if (start < end) {
            int mid = start + (end-start)/2;
            divide(start, mid, nums, index);
            divide(mid+1, end, nums, index);
            conquer(start, mid, end, nums, index);
        }
    }
    void conquer(int start, int mid, int end, vector<int> &nums, vector<int> &index) {
        vector<int> cpynums, cpyindex;
        int left = start, right = mid+1, lower = 0;
        while (left <= mid && right <= end) {
            if (index[left]+lower >= index[right]) {
                cpynums.push_back(nums[right]);
                cpyindex.push_back(index[right]);
                ++right;
                ++lower;
            } else {
                cpynums.push_back(nums[left]);
                cpyindex.push_back(index[left]+lower);
                ++left;
            }
        }
        while (left <= mid) {
            cpynums.push_back(nums[left]);
            cpyindex.push_back(index[left]+lower);
            ++left;
        }
        while (right <= end) {
            cpynums.push_back(nums[right]);
            cpyindex.push_back(index[right]);
            ++right;
        }
        for (int i = start; i <= end; ++i) {
            nums[i] = cpynums[i-start];
            index[i] = cpyindex[i-start];
        }
    }
};

//--- method 2: insertion O(n^2)
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n = nums.size();
        vector<int> res(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = n-1; j >= index[i]+1; --j) {
                res[j] = res[j-1];
            }
            res[index[i]] = nums[i];
        }
        return res;
    }
};