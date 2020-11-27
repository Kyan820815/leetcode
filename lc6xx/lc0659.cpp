//--- Q: 659. Split Array into Consecutive Subsequences

//--- method 1: O(1) space O(n) time
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int c1 = 1, c2 = 0, c3 = 0;
        int p1 = 0, p2 = 0, p3 = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i-1]) {
                if (p1 > 0) {
                    --p1;
                    ++c2;
                } else if (p2 > 0) {
                    --p2;
                    ++c3;
                } else if (p3 > 0) {
                    --p3;
                    ++c3;
                } else {
                    ++c1;
                }
            } else if (nums[i] == nums[i-1] + 1) {
                if (p1 > 0 || p2 > 0) {
                    return false;
                }
                p1 = c1, p2 = c2, p3 = c3;
                c1 = c2 = c3 = 0;
                if (p1 > 0) {
                    --p1;
                    ++c2;
                } else if (p2 > 0) {
                    --p2;
                    ++c3;
                } else if (p3 > 0) {
                    --p3;
                    ++c3;
                } else {
                    ++c1;
                }
            } else {
                if (c1 > 0 || c2 > 0) {
                    return false;
                }
                c1 = 1;
                c2 = c3 = p1 = p2 = p3 = 0;
            }
        }
        return !c1 && !c2;
    }
};

//--- method 2: O(n) space and time, two pass
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> cnt, last;
        for (int i = 0; i < nums.size(); ++i) {
            ++cnt[nums[i]];
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (!cnt[nums[i]]) {
                continue;
            }
            --cnt[nums[i]];
            if (last[nums[i]-1] > 0) {
                --last[nums[i]-1];
                ++last[nums[i]];
            } else if (cnt[nums[i]+1] && cnt[nums[i]+2]) {
                --cnt[nums[i]+1];
                --cnt[nums[i]+2];
                ++last[nums[i]+2];
            } else {
                return false;
            }
        }
        return true;
    }
};

