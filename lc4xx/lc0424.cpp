//--- Q: 424. Longest Repeating Character Replacement

//--- method 1: sliding window
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> str(26, 0);
        int maxCnt = 0, res = 0, start = 0;
        for (int i = 0; i < s.size(); ++i)
        {
        	maxCnt = max(maxCnt, ++str[s[i]-'A']);
        	while (i-start+1 - maxCnt > k)
        	{
        		--str[s[start]-'A'];
        		start++;
        	}
        	res = max(res, i-start+1);
        }
        return res;
    }
};