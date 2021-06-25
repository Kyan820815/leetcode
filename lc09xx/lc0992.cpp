//--- Q: 992. Subarrays with K Different Integers

//--- method 1: sliding window two pass
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

//--- method 2: sliding window one pass
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        unordered_map<int, int> map;
        int left = 0, right = 0, res = 0, prefix = 0;
        while (right < A.size()) {
            if (!map[A[right]]++) {
                --K;
            }
            if (K < 0) {
                --map[A[left++]];
                prefix = 0;
                ++K;
            }
            while (map[A[left]] > 1) {
                --map[A[left++]];
                ++prefix;
            }
            if (!K) {
                res += prefix + 1;
            }
            ++right;
        }
        return res;
    }
};