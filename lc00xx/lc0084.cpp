//--- Q: 0084. Largest Rectangle in Histogram

//--- method 1: stack operation
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> sk = {-1};
        int res = 0;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); ++i) {
            while (sk.back() != -1 && heights[sk.back()] > heights[i]) {
                int idx = sk.back();
                sk.pop_back();
                res = max(res, (i-sk.back()-1)*heights[idx]);
            }
            sk.push_back(i);
        }
        return res;
    }
};