//--- Q: 409. Longest Palindrome

//--- method 1: elegant version
class Solution {
public:
    int longestPalindrome(string s) {
        int up[26] = {0};
        int lw[26] = {0};
        int len = 0, odd = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] < 'a') up[s[i]-'A']++;
            else lw[s[i]-'a']++;
        }
        for (int i = 0; i < 26; ++i)
        {
            if (lw[i] % 2 == 1) odd++;
            if (up[i] % 2 == 1) odd++;
        }
        if (!odd) return s.length();
        else return s.length()-odd+1;
    }
};

//--- method 2: find largest odd & even, then add
class Solution {
public:
    int longestPalindrome(string s) {
  		int ch[256] = {0};
  		int len = 0, odd = 0;
  		for (int i = 0; i < s.size(); ++i)
  			ch[s[i]] += 1;
  		for (int i = 0; i < 256; ++i)
  		{
  			if (ch[i] > 0)
  			{
  				if (ch[i] % 2 == 0)
  					len += ch[i];
  				else
  				{
  					odd = 1;
  					len += ch[i]-1;
  				}
  			}
  		}
  		return len+odd;
    }
};