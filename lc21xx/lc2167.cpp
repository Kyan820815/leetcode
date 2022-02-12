//--- Q: 2167. Minimum Time to Remove All Cars Containing Illegal Goods

//--- method 1: one pass O(1) space greedy
class Solution {
public:
    int minimumTime(string s) {
        int n = s.size(), res = INT_MAX, left = 0;
        for (int i = 0 ; i < n; ++i) {
            left = min(i+1, left+2*(s[i]-'0'));
            res = min(res, left+n-i-1);
        }
        return res;
    }
};

//--- method 2: one pass O(1) space dp
class Solution {
public:
    int minimumTime(string s) {
        int n = s.size(), minv = INT_MAX, sum = 0;
        for (int i = 0; i < n; ++i) {
            if (sum > 0) {
                sum = 0;
            }
            sum += s[i] == '1' ? 1 : -1;
            minv = min(minv, sum);
        }
        return n+min(minv,0);
    }
};