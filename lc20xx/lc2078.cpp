//--- Q: 2078. Two Furthest Houses With Different Colors

//--- method 1: greedy
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int i = 0, j = n-1;
        while (i < n && colors[i] == colors[n-1]) {
            ++i;
        }
        while (j >= 0 && colors[j] == colors[0]) {
            --j;
        }
        return max(j, n-i-1);
    }
};

//--- method 2: find min and max index for each color
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        vector<vector<int>> idx(101);
        for (int i = 0; i < n; ++i) {
            idx[colors[i]].push_back(i);
        }
        int res = 0, minv = INT_MAX, maxv = INT_MIN;
        for (int i = 0; i <= 100; ++i) {
            if (!idx[i].size()) {
                continue;
            }
            if (minv == INT_MAX) {
                minv = idx[i].front(), maxv = idx[i].back();
            } else {
                res = max(res, max(abs(maxv-idx[i].front()), abs(minv-idx[i].back())));
                minv = min(minv, idx[i].front());
                maxv = max(maxv, idx[i].back());
            }
        }
        return res;
    }
};