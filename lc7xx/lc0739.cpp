//--- Q: 739. Daily Temperatures

//--- method 1: stack operation
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> sk, res(T.size(), 0);
        for (int i = 0; i < T.size(); ++i)
        {
        	while (sk.size() && T[sk.back()] < T[i])
        	{
        		res[sk.back()] = i-sk.back();
        		sk.pop_back();
        	}
        	sk.push_back(i);
        }
        return res;
    }
};