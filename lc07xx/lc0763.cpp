//--- Q: 763. Partition Labels

//--- method 1: two pass O(n)
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> times(26), res;
        int start = 0, end;
        for (int i = 0; i < S.size(); ++i)
        	times[S[i]-'a'] = i;

        end = times[S[0]-'a'];
        for (int i = 1; i < S.size(); ++i)
        {
        	if (i > end)
        	{
        		res.push_back(end-start+1);
        		start = end+1;
        	}
        	end = max(end, times[S[i]-'a']);
        }
        res.push_back(end-start+1);
        return res;
    }
};