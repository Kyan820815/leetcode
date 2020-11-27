//--- Q: 1295. Find Numbers with Even Number of Digits

//--- method 1: O(n) time
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >= 10 && nums[i] < 100
               || nums[i] >=1000 && nums[i] < 10000
               || nums[i] == 100000) {
                ++res;
            }
        }
        return res;
    }
};

//--- method 2: O(n*k) time, digit by digit check
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int digit = 0;
            while (nums[i]) {
                ++digit;
                nums[i] /= 10;
            }
            if (!(digit&1)) {
                ++res;
            }
        }
        return res;
    }
};