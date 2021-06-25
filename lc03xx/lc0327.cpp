//--- Q: 327. Count of Range Sum

//--- method 1: divide & conquer
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        res = 0;
        vector<long long int> sum(nums.size()+1, 0);
        for (int i = 1; i <= nums.size(); ++i) {
            sum[i] = sum[i-1] + nums[i-1];
        }
        divide(0, nums.size(), sum, lower, upper);
        return res;
    }
    void divide(int start, int end, vector<long long int> &sum, int lower, int upper) {
        if (start < end) {
            int mid = (end - start) / 2 + start;
            divide(start, mid, sum, lower, upper);
            divide(mid+1, end, sum, lower, upper);
            conquer(start, mid, end, sum, lower, upper);
        }
    }
    void conquer(int start, int mid, int end, vector<long long int> &sum, int lower, int upper) {
        int i = start, j = mid+1;
        int l = mid+1, u = mid+1;
        vector<int> copy;
        for (int i = start; i <= mid; ++i) {
            while (l <= end && sum[l]-sum[i] < lower) {
                ++l;
            }
            while (u <= end && sum[u]-sum[i] <= upper) {
                ++u;
            }
            while (j <= end && sum[i] > sum[j]) {
                copy.push_back(sum[j++]);
            }
            copy.push_back(sum[i]);
            res += u-l;
        }
        while (j <= end) {
            copy.push_back(sum[j++]);
        }
        for (int i = start; i <= end; ++i) {
            sum[i] = copy[i-start];
        }
    }
    int res;
};	