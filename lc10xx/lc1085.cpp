//--- Q: 1085. Sum of Digits in the Minimum Number

//--- method 1: simple finding sum of minv digits
class Solution {
public:
    int sumOfDigits(vector<int>& A) {
        int minv = INT_MAX;
        for (int i = 0; i < A.size(); ++i) {
            minv = min(minv, A[i]);
        }
        int res = 0;
        while (minv) {
            res += minv%10;
            minv /= 10;
        }
        return !(res&1);
    }
};