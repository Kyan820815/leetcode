//--- Q: 28. Implement strStr()

//--- method 1: one pass
class Solution {
public:
    int strStr(string haystack, string needle) {
		if (!needle.size()) return 0;
        if (!haystack.size()) return -1;
        int hlen = haystack.size(), nlen = needle.size();
       
        for (int i = 0; i <= hlen-nlen; ++i)
        {
        	bool valid = true;
        	for (int j = 0; j < nlen; ++j)
        	{
        		if (haystack[i+j] != needle[j])
        		{
        			valid = false;
        			break;
        		}
        	}
        	if (valid)
        		return i; 
        }
        return -1;
    }
};