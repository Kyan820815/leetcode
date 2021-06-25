//--- Q: 228. Summary Ranges

//--- method 1: clean code
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (!nums.size()) {
            return res;
        }
        for (int i = 0; i < nums.size(); ++i) {
            string now = to_string(nums[i]);
            while (i != nums.size()-1 && nums[i+1]-1 == nums[i]) {
                ++i;
            }
            string back = to_string(nums[i]);
            if (now == back) {
                res.push_back(back);
            } else {
                res.push_back(now + "->" +  back);
            }
        }
        return res;
    }
};

//--- method 2: linear pass
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (!nums.size()) {
            return res;
        }
        string now = to_string(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i]-1 != nums[i-1]) {
                string back = to_string(nums[i-1]);
                if (now == back) {
                    res.push_back(back);
                } else {
                    res.push_back(now + "->" +  back);
                }
                now = to_string(nums[i]);
            }
        }
        if (now == to_string(nums.back())) {
            res.push_back(now);
        } else {
            res.push_back(now + "->" +  to_string(nums.back()));
        }
        return res;
    }
};