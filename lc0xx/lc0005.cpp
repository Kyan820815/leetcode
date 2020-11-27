//--- Q: 005. Longest Palindromic Substring

//--- method 1: linear search, my version, better
class Solution {
public:
    string longestPalindrome(string s) {
        int left, right, start = 0, maxL = 0;
        for (int i = 0; i < s.size();)
        {
            if (s.size()-i <= maxL/2) break;
            left = right = i;
            while(right < s.size())
            {
                if (s[right] == s[left]) right++;
                else break;
            }

            i = right; left--;

            while(left >= 0 && right < s.size())
            {
                if (s[left] == s[right])
                    left--; right++;
                else break;
            }
            if (right-left-1 > maxL)
            {
                start = left+1;
                maxL = right-left-1;
            }
        }
        return s.substr(start,maxL);
    }
};

//--- method 2: linear search, better
class Solution {
public:
    string longestPalindrome(string s) {
    	int start=0, maxLength=0;
    	int left, right;
    	
    	if (s.size() < 2)
    		return s;

    	for (int i = 0; i < s.size();)
    	{
    		left = right = i;
    		
    		if (s.size()-i <= maxLength/2)
    			break;

    		while(right < s.size())
    		{
				if (s[right] == s[right+1])
					right++;
				else
				{
					left--;
					right++;
					i = right;
					break;    			
				}
    		}

    		while(left>=0 && right<s.size() && s[left]==s[right])
    		{
    			left--;
    			right++;
    		}

    		if ((right-1)-(left+1)+1 > maxLength)
    		{
    			maxLength = (right-1)-(left+1)+1;
    			start = left+1;
    		}
    	}
		return s.substr(start,maxLength);	
    }
};

//--- method 3: dp
class Solution {
public:
    string longestPalindrome(string s) {
    	int pLength = s.size();
    	int start=0, maxLength=1;    	

    	if (pLength < 2)
    		return s;

    	int pmatrix[s.size()][s.size()] = {0};
    	
    	for (int i = 0; i < pLength; i++)
    	{
    		pmatrix[i][i] = 1;
    		if (i+1 < pLength && s[i] == s[i+1])
    		{
    			pmatrix[i][i+1] = 1;
    			maxLength = 2;
    			start = i; 
    		}
    	}

    	for (int i = pLength-3; i >= 0; i--)
    	{
    		for (int j = i+2; j < pLength; j++)
    		{
    			if (pmatrix[i+1][j-1] == 1 && (s[i] == s[j]))
	    		{
	    			pmatrix[i][j] = 1;
	    			if (j-i+1 >= maxLength)
	    			{
	    				start = i;
	    				maxLength = j-i+1;
	    			}
	    		}
    		}
    	}
    	return s.substr(start, maxLength);
    }
};	

//--- method 4: brute force
class Solution {
public:
    string longestPalindrome(string s) {
    	int pLength = s.size();
    	int start;
    	int shift;
    	int idx;
    	bool find = false;
    	while(pLength > 1)
    	{
    		start = 0;
    		while(start+pLength <= s.size())
    		{
    			shift = 0;
    			for (idx = start; idx < start+pLength/2; idx++)
	    		{
	    			if (s[idx] != s[start+pLength-1-shift])
	    				break;
	    			shift++;
	    		}
	    		if (idx >= start+pLength/2)
	    		{
	    			find = true;
	    			break;
	    		}
	    		start++;
    		}
    		if (find)
    		{
    			return s.substr(start, pLength);
    		}
    		pLength--;
    	}
		return s.substr(0,1);	
    }
};