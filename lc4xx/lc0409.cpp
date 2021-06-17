//--- Q: 409. Longest Palindrome

//--- method 1: elegant version
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> cnt(128, 0);
        for (auto &ch: s) {
            ++cnt[ch];
        }
        int odd = 0, res = 0;
        for (int i = 0; i < 128; ++i) {
            if (cnt[i]&1) {
                odd = 1;
                --cnt[i];
            }
            res += cnt[i];
        }
        return res + odd;
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