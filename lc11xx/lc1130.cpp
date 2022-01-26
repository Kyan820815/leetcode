//--- Q: 1130. Minimum Cost Tree From Leaf Values

//--- method 1: O(n) monotonic decreasing stack
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size(), res = 0;
        vector<int> sk;
        for (auto &val: arr) {
            while (sk.size() && sk.back() < val) {
                auto mid = sk.back();
                sk.pop_back();
                int left = !sk.size() ? INT_MAX : sk.back()*mid;
                int right = mid*val;
                res += min(left, right);
            }
            sk.push_back(val);
        }
        for (int i = 0; i < sk.size()-1; ++i) {
            res += sk[i]*sk[i+1];
        }
        return res;
    }
};