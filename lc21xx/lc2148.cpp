//--- Q: 2148. Count Elements With Strictly Smaller and Greater Elements

//--- method 1: two pass
class Solution {
public:
    int countElements(vector<int>& nums) {
        int minv = INT_MAX, maxv = INT_MIN, res = 0;
        for (auto &num: nums) {
            minv = min(minv, num);
            maxv = max(maxv, num);
        }
        for (auto &num: nums) {
            res += num != minv && num != maxv;
        }
        return res;
    }
};

//--- method 2: one pass
class Solution {
public:
    int countElements(vector<int>& nums) {
        int n = nums.size(), minv = INT_MAX, mincnt = 0, maxv = INT_MIN, maxcnt = 0;
        for (int i = 0; i < n; ++i) {
            if (minv > nums[i]) {
                minv = nums[i];
                mincnt = 1;
            } else if (minv == nums[i]) {
                ++mincnt;
            }
            if (maxv < nums[i]) {
                maxv = nums[i];
                maxcnt = 1;
            } else if (maxv == nums[i]) {
                ++maxcnt;
            }
        }
        return minv == maxv ? 0 :n-mincnt-maxcnt;
    }
};