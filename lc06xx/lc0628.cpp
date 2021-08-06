//--- Q: 0628. Maximum Product of Three Numbers

//--- method 1: sort
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return max(nums[0]*nums[1]*nums.back(), nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3]);
    }
};

//--- method 2: O(n)
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        vector<int> large(3, INT_MIN), small(2, INT_MAX);
        for (auto &num: nums) {
            if (large[0] <= num) {
                large[2] = large[1];
                large[1] = large[0];
                large[0] = num;
            } else if (large[1] <= num) {
                large[2] = large[1];
                large[1] = num;
            } else if (large[2] < num) {
                large[2] = num;
            }
            if (small[0] >= num) {
                small[1] = small[0];
                small[0] = num;
            } else if (small[1] > num) {
                small[1] = num;
            }
        }
        return max(large[0]*large[1]*large[2], large[0]*small[0]*small[1]);
    }
};