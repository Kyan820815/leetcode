//--- Q: 0739. Daily Temperatures

//--- method 1: stack operation
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> sk, res(n, 0);
        for (int i = 0; i < n; ++i) {
            while (sk.size() && temperatures[sk.back()] < temperatures[i]) {
                res[sk.back()] = i-sk.back();
                sk.pop_back();
            }
            sk.push_back(i);
        }
        return res;
    }
};