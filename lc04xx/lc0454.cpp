//--- Q: 454. 4Sum II

//--- method 1: O(n^2) hashmap
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> map;
        int res = 0;
        for (int i = 0; i < A.size(); ++i)
        {
        	for (int j = 0; j < B.size(); ++j)
        		++map[A[i]+B[j]];
        }
        for (int i = 0; i < C.size(); ++i)
        {
        	for (int j = 0; j < D.size(); ++j)
        	{
        		int sum = (C[i]+D[j])*(-1);
        		if (map.find(sum) != map.end())
                    res += map[sum];
        	}
        }
        return res;
    }
};