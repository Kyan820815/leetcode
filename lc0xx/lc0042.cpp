//--- Q; 42. Trapping Rain Water

//--- method 1: dp and find max of left & right side
class Solution {
public:
    int trap(vector<int>& height) {
    	int maxv = 0, res = 0;
    	vector<int> dp(height.size(), 0);
    	for (int i = 0; i < height.size(); ++i)
    	{
    		dp[i] = maxv;
    		maxv = max(maxv, height[i]);
    	}
    	maxv = 0;
    	for (int i = height.size()-1; i >= 0; --i)
    	{
    		dp[i] = min(dp[i], maxv);
    		maxv = max(maxv, height[i]);
    		if (dp[i]-height > 0)
    			res += dp[i]-height[i];
    	}
    	return res;
    }
};

//--- method 2: double pointer left & right
class Solution {
public:
    int trap(vector<int>& height) {
    	int left = 0, right = height.size()-1;
        int res = 0;
    	while (left < right)
    	{
    		if (height[left] < height[right])
    		{
    			int minv = height[left++];
    			while (left < right && height[left] < minv)
    				res += minv - height[left++];
    		}
    		else
    		{
    			int minv = height[right--];
    			while (left < right && height[right] < minv)
    				res += minv - height[right--];
    		}
    	}
    	return res;
    }
};

//--- method 3: stack
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> sk;
        int res = 0;
        for (int i = 0; i < height.size(); ++i) {
            while (sk.size() && height[sk.back()] < height[i]) {
                auto idx = sk.back();
                sk.pop_back();
                if (sk.size()) {
                    res += (min(height[sk.back()], height[i])-height[idx])*(i-sk.back()-1);
                }
            }
            sk.push_back(i);
        }
        return res;
    }
};