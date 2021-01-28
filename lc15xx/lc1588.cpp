//--- Q: 1588. Sum of All Odd Length Subarrays

//--- method 1: O(n) time find A[i] occurences
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size(), res = 0;
        for (int i = 0; i < n; ++i) {
            res += ((i+1)*(n-i)+1)/2*arr[i];
        }
        return res;
    }
};