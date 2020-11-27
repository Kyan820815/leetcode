//--- Q: 395. Longest Substring with At Least K Repeating Characters

//--- method 1: O(n^2) mask operation
class Solution {
public:
    int longestSubstring(string s, int k) {
        vector<int> str(26, 0);	
        int max_idx = 0, res = INT_MIN, i = 0;
        if (s.size() == 0) return 0;
        while (i+k <= s.size())
        {
        	int mask = 0;
        	max_idx = i;
        	for (int j = i; j < s.size(); ++j)
        	{
                int idx = s[j]-'a';
	        	++str[idx];

				if (str[idx] >= k)
					mask = mask & ~(1 << idx);
				else
		        	mask = mask | (1 << idx);

				if (mask == 0 && res < j-i+1)
				{
					res = j-i+1;
					max_idx = j;
				}
        	}
        	str = vector<int>(26, 0);
        	i = max_idx+1;
        }
        return res == INT_MIN ? 0 : res;
    }
};

//--- method 2: recursion O(n)
class Solution {
public:
    int longestSubstring(string s, int k) {
        vector<int> str(26, 0);	
        int max_idx = 0, res = INT_MIN, n = s.size();
        bool ok = true;
        if (s.size() == 0) return 0;
        for (int i = 0; i < n; ++i)
        	++str[s[i] - 'a'];
        for (int i = 0; i < n; ++i)
        {
        	if (str[s[i] - 'a'] < k)
        	{
        		res = max(res, longestSubstring(s.substr(max_idx, i-max_idx), k));
        		max_idx = i+1;
        		ok = false;
        	}
        }
        return ok ? n : max(res, longestSubstring(s.substr(max_idx, n-max_idx), k));
    }
}; 

//--- method 3: recursion O(n) with left right partition
class Solution {
public:
    int longestSubstring(string s, int k) {
        vector<int> str(26, 0);	
        int n = s.size(), idx = 0;
        if (s.size() == 0) return 0;
        for (int i = 0; i < n; ++i)
        	++str[s[i] - 'a'];

        while (idx < n && str[s[idx] - 'a'] >= k) ++idx;
        if (idx == n) return n;
        int left = longestSubstring(s.substr(0, idx), k);

        while (idx < n && str[s[idx] - 'a'] < k) ++idx;
        int right = longestSubstring(s.substr(idx, n-idx), k);

        return max(left, right);
    }
}; 