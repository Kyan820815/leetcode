//--- Q: 1004. Max Consecutive Ones III

//--- method 1: sliding window with clean code, better
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
    	int i = 0, j;
    	for (j = 0; j < A.size(); ++j)
    	{
    		if (!A[j]) --K;
    		if (K < 0 && !A[i++]) ++K;
    	}
    	return j-i;
    }
};

//--- method 2: sliding window
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int ones = 0, left = 0, res = 0;
        for (int i = 0; i < A.size(); ++i)
        {
            if (A[i]) ++ones;
            if (i-left+1 - ones > K)
            {
                if (A[left]) --ones;
                ++left;
            }
            res = max(res, i-left+1);
        }
        return res;
    }
};