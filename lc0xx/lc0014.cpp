//--- Q: 014. Longest Common Prefix

//--- method 1: vertical scanning, better
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	if (strs.size() == 0)
    		return "";

    	for (int i = 0; i < strs[0].size(); ++i)
    	{
    		for (int j = 1; j < strs.size(); ++j)
    		{ 
				if ((i+1) > strs[j].size() || strs[0][i] != strs[j][i])
                    return strs[0].substr(0, i);
    		}
    	}
    	return strs[0];
    }
};

//--- method 2: horizontal scanning
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minIdx;

        if (strs.size() == 0)
            return "";

        minIdx = strs[0].size();

        for (int i = 0; i < strs.size()-1; ++i)
        {
            minIdx = (minIdx < strs[i+1].size()) ? minIdx : strs[i+1].size();
            for (int j = 0; j < minIdx; ++j)
            {
                if (strs[i][j] != strs[i+1][j])
                {
                    minIdx = j;
                    break;
                }
            }
            if (minIdx == 0)   
                break;
        }
        return strs[0].substr(0,minIdx);
    }
};

//--- method 3: divide and conquer
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string long_str;
        if (strs.size() == 0) return "";
        mergesort(strs, 0, strs.size()-1, long_str);
        return long_str;
    }

    void mergesort(vector<string>& strs, int start, int end, string &long_str)
    {
        int mid;
        string long_l, long_r;
        if (start < end)
        {
            mid = (start+end)/2;
            mergesort(strs, start, mid, long_l);
            mergesort(strs, mid+1, end, long_r);
            merge(long_l, long_r, long_str);
        }
        else long_str = strs[start];
    }

    void merge(string left, string right, string &long_str)
    {
        int minIdx;
        minIdx = (left.size() < right.size()) ? left.size() : right.size();

        for (int i = 0; i < minIdx; ++i)
        {
            if (left[i] != right[i])
            {
                minIdx = i;
                break;
            }
        }
        long_str = left.substr(0,minIdx);
    }
};

//--- method 4: binary search
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string long_str;
        int low, high;
        int mid, minL;
        
        if (strs.size() == 0) return "";
        minL = strs[0].size();
        for (int i = 1; i < strs.size(); ++i)
            if (strs[i].size() < minL)
                minL = strs[i].size();

        low = 0, high = minL-1;

        while(low < high)
        {
            mid = (low+high)/2;
            if (!findLCP(strs,mid))
                high = mid;
            else
                low = mid+1;
        }
        if (findLCP(strs,low))
            return strs[0].substr(0,low+1);
        else return strs[0].substr(0,low);
    }

    bool findLCP(vector<string>& strs, int L)
    {
        string comp = strs[0].substr(0,L+1);
        for (int i = 1; i < strs.size(); ++i)
        {
            if (comp.compare(strs[i].substr(0,L+1)) != 0)
                return false;
        }
        return true;
    }
};