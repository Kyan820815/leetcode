//--- Q: 1035. Uncrossed Lines

//--- method 1: dp, O(n^2) space
class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
    	vector<vector<int>> dp(A.size(), vector<int>(B.size(), 0));
        for (int i = 0; i < A.size(); ++i)
        {
        	for (int j = 0; j < B.size(); ++j)
        	{
        		if (A[i] == B[j])
        			dp[i][j] = max(((i-1 >= 0 && j-1 >= 0) ? dp[i-1][j-1] : 0) + 1, dp[i][j]);
        		else
	        		dp[i][j] = max(j-1 >= 0 ? dp[i][j-1] : 0, i-1 >= 0 ? dp[i-1][j] : 0);
        	}
        }
        return dp[A.size()-1][B.size()-1];
    }
};

//--- method 2-1-1: dp, O(n) space, clean code
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> dp(n2+1, 0);
        for (int i = 1; i <= n1; ++i) {
            int last, now = 0;
            for (int j = 1; j <= n2; ++j) {
                last = dp[j];
                if (nums1[i-1] == nums2[j-1]) {
                    dp[j] = now+1;
                } else {
                    dp[j] = max(dp[j], dp[j-1]);
                }
                now = last;
            }
        }
        return dp.back();
    }
};

//--- method 2-1-2: dp, O(n) space, clean code
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> dp(n2, 0);
        for (int i = 0; i < n1; ++i) {
            int last, now = 0;
            for (int j = 0; j < n2; ++j) {
                last = dp[j];
                if (nums1[i] == nums2[j]) {
                    dp[j] = now+1;
                } else {
                    dp[j] = max(dp[j], j ? dp[j-1] : 0);
                }
                now = last;
            }
        }
        return dp.back();
    }
};


//--- method 2-2: dp, O(n) space
class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
    	vector<int> dp(B.size(), 0);
    	vector<int> pre(B.size(),0);
        for (int i = 0; i < A.size(); ++i)
        {
        	for (int j = 0; j < B.size(); ++j)
        	{
        		if (A[i] == B[j])
        			dp[j] = max((j-1 >= 0 ? pre[j-1] : 0) + 1, dp[j]);
        		else
	        		dp[j] = max(dp[j], (j-1 >= 0 ? dp[j-1] : 0));
        	}
        	pre = dp;
        }
        return dp[B.size()-1];
    }
};

//--- method 2-3: dp, O(n) space
class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
    	vector<int> dp(B.size(), 0);
    	int last = 0;
        for (int i = 0; i < A.size(); ++i)
        {
        	for (int j = 0; j < B.size(); ++j)
        	{
        		int save = dp[j];
        		if (A[i] == B[j])
        			dp[j] = max((j-1 >= 0 ? last : 0) + 1, dp[j]);
        		else
	        		dp[j] = max(dp[j], (j-1 >= 0 ? dp[j-1] : 0));
	        	last = save;
        	}
        }
        return dp[B.size()-1];
    }
};
