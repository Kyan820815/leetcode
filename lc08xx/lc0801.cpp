//--- Q: 801. Minimum Swaps To Make Sequences Increasing

//--- mehtod 1: dp iteration, O(n) space
class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
    	int n =  A.size();
        vector<int> swap(n, n), noswap(n, n);
        swap[0] = 1, noswap[0] = 0;
        for (int i = 1; i < n; ++i)
        {
        	if (A[i] > A[i-1] && B[i] > B[i-1])
        	{
        		noswap[i] = noswap[i-1];
        		swap[i] = swap[i-1] + 1;
        	}
        	if (A[i] > B[i-1] && B[i] > A[i-1])
        	{
        		swap[i] = min(swap[i], noswap[i-1]+1);
        		noswap[i] = min(noswap[i], swap[i-1]);
        	}
        }
        return min(swap[n-1], noswap[n-1]);
    }
};

//--- method 2: dp iteration, O(1) space
class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
    	int n =  A.size();
    	int swap = 1, noswap = 0;
        for (int i = 1; i < n; ++i)
        {
        	int pre_swap = swap, pre_noswap = noswap;
            noswap = swap = n;
        	if (A[i] > A[i-1] && B[i] > B[i-1])
        	{
        		noswap = pre_noswap;
        		swap = pre_swap+1;
        	}
        	if (A[i] > B[i-1] && B[i] > A[i-1])
        	{
        		noswap = min(noswap, pre_swap);
        		swap = min(swap, pre_noswap+1);
        	}
        }
        return min(noswap, swap);
    }
};