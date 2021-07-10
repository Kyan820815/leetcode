//--- Q: 0228. Summary Ranges

//--- method 1: clean code
cclass Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (!nums.size()) {
            return {};
        }
        vector<string> res;
        int last = nums[0];
        for (int i = 1; i <= nums.size(); ++i) {
            if (i == nums.size() || nums[i]-1 > nums[i-1]) {
                string str = to_string(last) + ((nums[i-1] != last) ? "->"+to_string(nums[i-1]) : "");
                if (i < nums.size()) {
                    last = nums[i];
                }
                res.push_back(str);
            }
        }
        return res;
    }
};