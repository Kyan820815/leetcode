//--- Q: 389. Find the Difference

//--- method 1: count times of s and delte from t
class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> times(26,0);
        for (int i = 0; i < s.size(); ++i)
        	++times[s[i]-'a'];
        for (int i = 0; i < t.size(); ++i)
        	if (--times[t[i]-'a'] < 0)
        		return t[i];
        return 'a';
    }
};

//--- method 2: bit operation;
class Solution {
public:
    char findTheDifference(string s, string t) {
    	char c = 0;
        for (int i = 0; i < s.size(); ++i)
        	c ^= s[i];
        for (int i = 0; i < t.size(); ++i)
        	c ^= t[i];
        return c;
    }
};