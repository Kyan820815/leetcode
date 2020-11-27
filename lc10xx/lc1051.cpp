//--- Q: 1051. Height Checker

//--- method 1: nlolg n sort
class Solution {
public:
    int heightChecker(vector<int>& heights) {
    	vector<int> tmp = heights;
    	int res = 0;
        sort(tmp.begin(), tmp.end());
        for (int i = 0; i < heights.size(); ++i)
        {
        	if (tmp[i] != heights[i]) ++res;
        }
        return res;
    }
};