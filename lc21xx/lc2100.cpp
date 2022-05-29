//--- Q: 2100. Find Good Days to Rob the Bank

//--- method 1: prefix & suffix array
class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> left(n), right(n), res;
        int lcnt = 0, rcnt = 0;
        for (int i = 1, j = n-2; i < n; ++i, --j) {
            lcnt = security[i-1] >= security[i] ? lcnt+1 : 0;
            rcnt = security[j] <= security[j+1] ? rcnt+1 : 0;
            left[i] = lcnt;
            right[j] = rcnt;
        }
        for (int i = 0; i < n; ++i) {
            int cnt = min(left[i], right[i]);
            if (cnt >= time) {
                res.push_back(i);
            }
        }
        return res;
    }
};