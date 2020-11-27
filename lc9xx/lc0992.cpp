//--- Q: 992. Subarrays with K Different Integers

//--- method 1: sliding window
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return atmostK(A, K) - atmostK(A, K-1);        
    }
    int atmostK(vector<int> &A, int K)
    {
        unordered_map<int, int> map;
        int j = 0, res = 0;
        for (int i = 0; i < A.size(); ++i)
        {
            if (!map[A[i]]) --K;
            map[A[i]]++;
            while (K < 0)
            {
                --map[A[j]];
                if (!map[A[j]]) ++K;
                ++j;
            }
            res += i-j+1;
        }
        return res;
    }
};