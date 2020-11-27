//--- Q: 84. Largest Rectangle in Histogram

//--- method 1: stack operation
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> sk;
        heights.push_back(0);
        int res = INT_MIN;
        for (int i = 0; i < heights.size(); ++i)
        {
        	while (sk.size() && heights[sk.top()] >= heights[i])
        	{
        		int cur = sk.top();
        		sk.pop();
                int now = (i-(!sk.size() ? 0 : sk.top()+1)) * heights[cur];
                res = max(res, now); 
        	}
        	sk.push(i);
        }
        return res == INT_MIN ? 0 : res;
    }
};