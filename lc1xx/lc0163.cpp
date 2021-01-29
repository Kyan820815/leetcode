//--- Q: 163. Missing Ranges

//--- method 1: clean code
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        nums.push_back(upper+1);
        int last = lower-1, n = nums.size();
        for (int i = 0; i < n; ++i) {
            int d = nums[i] - last;
            if (d == 2) {
                res.push_back(to_string(nums[i]-1));
            } else if (d > 2) {
                res.push_back(to_string(last+1) + "->" + to_string(nums[i]-1));
            }
            last = nums[i];
        }
        return res;
    }
};

//--- method 2: my version
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        if (!nums.size()) {
            return lower == upper ? vector<string>({to_string(lower)}) : vector<string>({to_string(lower) + "->" + to_string(upper)});
        }
        if (lower == upper) {
            return {};
        }
        if (nums[0] - lower == 1) {
            res.push_back(to_string(lower));
        } else if (nums[0] - lower > 1) {
            res.push_back(to_string(lower) + "->" + to_string(nums[0]-1));
        }
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            int d = nums[i] - nums[i-1];
            if (d == 2) {
                res.push_back(to_string(nums[i]-1));
            } else if (d > 2) {
                res.push_back(to_string(nums[i-1]+1) + "->" + to_string(nums[i]-1));
            }
        }
        if (upper - nums.back() == 1) {
            res.push_back(to_string(upper));
        } else if (upper - nums.back() > 1) {
            res.push_back(to_string(nums.back()+1) + "->" + to_string(upper));
        }
        return res;
    }
};