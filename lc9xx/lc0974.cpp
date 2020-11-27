//--- Q: 974. Subarray Sums Divisible by K

//--- method 1: one pass
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int res = 0, right = 0, sum = 0;
        unordered_map<int, int> map;
        map[0] = 1;
        while (right < A.size()) {
            sum += A[right++];
            res += map[(sum%K+K)%K]++;
        }
        return res;
    }
};

//--- method 2: two pass
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
    	vector<int> dp(K, 0);
        int res = 0;
    	dp[0] = 1;
    	int sum = 0;
    	for (int i = 0; i < A.size(); ++i)
    	{
    		sum += A[i];
            int rem =(sum%K+K)%K;
    		dp[rem]++;
    	}
    	for (auto &d: dp)
    	{
    		int x = d-1;
    		res += (1+x)*x/2;
    	}
        return res;
    }
};
