//--- Q: 0659. Split Array into Consecutive Subsequences

//--- method 1: O(n) space and time, two pass
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> cnt, len;
        for (auto &num: nums) {
            ++cnt[num];
        }
        for (auto &num: nums) {
            if (!cnt[num]) {
                continue;
            }
            --cnt[num];
            if (len[num-1]) {
                --len[num-1];
                ++len[num];
            } else if (cnt[num+1] && cnt[num+2]) {
                --cnt[num+1];
                --cnt[num+2];
                ++len[num+2];
            } else {
                return false;
            }
        }
        return true;
    }
};