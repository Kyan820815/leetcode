//--- Q: 680. Valid Palindrome II

//--- method 1: check left and right
class Solution {
public:
    bool validPalindrome(string s) {
    	int left = 0, right = s.size()-1;
    	while (left < right)
    	{
    		if (s[left] != s[right])
    			return isvalid(s, left, right-1) || isvalid(s, left+1, right);
    		++left;
    		--right;
    	}
    	return true;
    }
    bool isvalid(string s, int start, int end)
    {
    	int left = start, right = end;
    	while (left < right)
    	{
    		if (s[left] != s[right])
    			return false;
    		++left;
    		--right;
    	}
    	return true;
    }
};