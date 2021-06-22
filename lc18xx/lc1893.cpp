//--- Q: 1893. Check if All the Integers in a Range Are Covered

//--- method 1: find interval
class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> used(right-left+2, 0);
        for (auto &range: ranges) {
            if (max(range[0], left) > min(range[1], right)) {
                continue;
            }
            int start = max(range[0], left);
            int end = min(range[1], right);
            ++used[start-left];
            --used[end+1-left];
        }
        int cnt = 0, now = left;
        for (int i = 0; i < used.size() && now <= right; ++i) {
            cnt += used[i];
            if (i+left == now && !cnt) {
                return false;
            }
            ++now;
        }
        return true;
    }
};

//--- method 2: sort
class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        sort(ranges.begin(), ranges.end());
        for (auto &range: ranges) {
            if (range[0] <= left && left <= range[1]) {
                left = range[1]+1;
            }
        }
        return left > right;
    }
};
