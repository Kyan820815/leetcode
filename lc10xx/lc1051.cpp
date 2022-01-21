//--- Q: 1051. Height Checker

//--- method 1: nlolg sort
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> tmp = heights;
        sort(tmp.begin(), tmp.end());
        int res = 0;
        for (int i = 0; i < heights.size(); ++i) {
            res += heights[i] != tmp[i];
        }
        return res;
    }
};

//--- method 2: counting sort
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> cnt(101, 0);
        for (auto &height: heights) {
            ++cnt[height];
        }
        int res = 0, idx = 0;
        for (auto &height: heights) {
            while (!cnt[idx]) {
                ++idx;
            }
            res += idx != height;
            --cnt[idx];
        }
        return res;
    }
};