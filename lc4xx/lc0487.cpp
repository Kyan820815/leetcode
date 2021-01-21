//--- Q: 487. Max Consecutive Ones II

//--- method 1: two pointer
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left = 0, right = 0, zeros = 0, res = 0;
        while (right < nums.size()) {
            if (!nums[right]) {
                ++zeros;
            }
            while (zeros > 1) {
                if (!nums[left++]) {
                    --zeros;
                }
            }
            res = max(res, right-left+1);
            ++right;
        }
        return res;
    }
};