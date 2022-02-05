//--- Q: 1920. Build Array from Permutation

//--- method 1: cycle processing
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= 0) {
                continue;
            }
            int last = -nums[i], idx = i;
            while (nums[idx] != i) {
                int next = nums[idx];
                nums[idx] = -nums[nums[idx]];
                idx = next;
            }
            nums[idx] = last;
        }
        for (auto &num: nums) {
            num = -num;
        }
        return nums;
    }
};

//--- method 2: modulo
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            nums[i] += n*(nums[nums[i]]%n);
        }
        for (auto &num: nums) {
            num /= n;
        }
        return nums;
    }
};