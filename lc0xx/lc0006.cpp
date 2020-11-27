//--- Q: 006. ZigZag Conversion

//--- method 1, better
class Solution {
public:
    string convert(string s, int numRows) {
    	string out_str(s.size(),' ');
		int jump = 2*numRows-2;
		int out_idx = 0;
		if (numRows == 1)
			return s;
		for (int r = 0; r < numRows; r++)
		{
			for (int idx = r; idx < s.size(); idx+=jump)
			{
				out_str[out_idx++] = s[idx];
				if (r>0 && r<numRows-1 && idx+jump+(-2)*r < s.size())
				{
					out_str[out_idx++] = s[idx+jump+(-2)*r];
				}
			}
		}
		return out_str;
    }
};

//--- method 2
class Solution {
public:
    string convert(string s, int numRows) {
    	string out_str(s.length(),' ');
    	int idx;
    	int out_idx = 0;

    	if (numRows == 1)
    		return s;

        for (int r = 0; r < numRows; r++)
        {
        	idx = r;
        	out_str[out_idx++] = s[idx];
        	if (out_idx == s.length())
        		break;
        	while(idx < s.length())
        	{
        		if ((r>0) && (r<numRows-1))
        		{
        			if ((idx+2*numRows-2) + (r)*(-2) >= s.length())
        				break;
        			out_str[out_idx++] = s[(idx+2*numRows-2) + (r)*(-2)];
        			if (out_idx == s.length())
        				break;
        		}

 				if (idx+2*numRows-2 >= s.length())
 					break;
        		out_str[out_idx++] = s[idx+2*numRows-2];
        		if (out_idx == s.length())
        			break;

        		idx = idx + 2*numRows-2;
        	}
        }
        return out_str;
    }
};