//--- Q: 1005. Maximize Sum Of Array After K Negations

//--- method 1: nlogn sort
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int idx = 0, sum = 0, minv = INT_MAX;
        while (idx < nums.size()) {
            if (nums[idx] < 0 && k) {
                sum -= nums[idx];
                --k;
            } else {
                sum += nums[idx];
            }
            minv = min(minv, abs(nums[idx++]));
        }
        return k&1 ? sum-2*minv : sum;
    }
};

//--- method 2: quick select O(n)
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int idx = 0, sum = 0, minv = INT_MAX;
        divide(0, nums.size()-1, nums, k);
        while (idx < nums.size()) {
            if (nums[idx] < 0 && k) {
                sum -= nums[idx];
                --k;
            } else {
                sum += nums[idx];
            }
            minv = min(minv, abs(nums[idx++]));
        }
        return k&1 ? sum-2*minv : sum;
    }
    void divide(int start, int end, vector<int> &nums, int k) {
        while (start < end) {
            int mid = partition(start, end, nums);
            if (mid < k) {
                start = mid+1;
            } else {
                end = mid;
            }
        }
    }
    int partition(int start, int end, vector<int> &nums) {
        int pivot = random()%(end-start+1)+start, idx = start-1;
        swap(nums[pivot], nums[end]);
        for (int i = start; i < end; ++i) {
            if (nums[i] < nums[end]) {
                swap(nums[++idx], nums[i]);
            }
        }
        swap(nums[++idx], nums[end]);
        return idx;
    }
};

//--- method 2: built in quick select O(n)
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.begin()+k, nums.end());
        int idx = 0, sum = 0, minv = INT_MAX;
        while (idx < nums.size()) {
            if (nums[idx] < 0 && k) {
                sum -= nums[idx];
                --k;
            } else {
                sum += nums[idx];
            }
            minv = min(minv, abs(nums[idx++]));
        }
        return k&1 ? sum-2*minv : sum;
    }
};