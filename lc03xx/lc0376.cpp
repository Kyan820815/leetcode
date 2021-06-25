//--- Q: 376. Wiggle Subsequence

//--- method 1: dp
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (!nums.size()) {
            return 0;
        }
        int down = 1, up = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i-1]) {
                up = down + 1;
            } else if (nums[i] < nums[i-1]) {
                down = up + 1;
            }
        }
        return max(up, down);
    }
};

//--- method 2: greedy
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (!nums.size()) {
            return 0;
        }
        int up = -1, res = 1, last = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > last) {
                if (!up || up == -1) {
                    ++res;
                    up = 1;
                }
            } else if (nums[i] < last) {
                if (up || up == -1) {
                    ++res;
                    up = 0;
                }
            }
            last = nums[i];
        }
        return res;
    }
};