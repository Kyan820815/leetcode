//--- Q: 0163. Missing Ranges

//--- method 1: clean code
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        int last = --lower;
        nums.push_back(upper+1);
        for (auto &num: nums) {
            int left = last+1, right = num-1, diff = right-left;
            if (diff >= 0) {
                res.push_back(diff == 0 ? to_string(left) : to_string(left)+"->"+to_string(right));
            }
            last = num;
        }
        return res;
    }
};