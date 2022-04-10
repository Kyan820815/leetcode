//--- Q: 2098. Subsequence of Size K With the Largest Even Sum

//--- method 1: built-in quick select
class Solution {
public:
    using ll = long long;
    long long largestEvenSum(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.begin()+k, nums.end(), greater<int>());
        ll sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        if (!(sum&1)) {
            return sum;
        }
        array<int,2> maxv = {-1,-1}, minv = {100001,100001};
        for (int i = 0; i < k; ++i) {
            minv[nums[i]&1] = min(minv[nums[i]&1], nums[i]);
        }
        for (int i = k; i < nums.size(); ++i) {
            maxv[nums[i]&1] = max(maxv[nums[i]&1], nums[i]);
        }
        ll res = -1;
        if (maxv[1] != -1 && minv[0] != 100001) {
            res = max(res, sum-minv[0]+maxv[1]);
        }
        if (maxv[0] != -1 && minv[1] != 100001) {
            res = max(res, sum-minv[1]+maxv[0]);
        }
        return res;
    }
};

//--- method 2: quick select
class Solution {
public:
    using ll = long long;
    long long largestEvenSum(vector<int>& nums, int k) {
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int mid = partition(left, right, nums);
            if (mid < k-1) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        ll sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        if (!(sum&1)) {
            return sum;
        }
        array<int,2> maxv = {-1,-1}, minv = {100001,100001};
        for (int i = 0; i < k; ++i) {
            minv[nums[i]&1] = min(minv[nums[i]&1], nums[i]);
        }
        for (int i = k; i < nums.size(); ++i) {
            maxv[nums[i]&1] = max(maxv[nums[i]&1], nums[i]);
        }
        ll res = -1;
        if (maxv[1] != -1 && minv[0] != 100001) {
            res = max(res, sum-minv[0]+maxv[1]);
        }
        if (maxv[0] != -1 && minv[1] != 100001) {
            res = max(res, sum-minv[1]+maxv[0]);
        }
        return res;
    }
    int partition(int left, int right, vector<int> &nums) {
        int pivot = random()%(right-left+1) + left;
        swap(nums[pivot], nums[right]);
        int idx = left-1;
        for (int i = left; i < right; ++i) {
            if (nums[i] > nums[right]) {
                swap(nums[++idx], nums[i]);
            }
        }
        swap(nums[++idx], nums[right]);
        return idx;
    }
};