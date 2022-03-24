//--- Q: 1663. Smallest String With A Given Numeric Value

//--- method 1: greedy forward
class Solution {
public:
    string getSmallestString(int n, int k) {
        string res = "";
        for (int i = 0; i < n; ++i) {
            int j;
            for (j = 1; j <= 26; ++j) {
                if (k-j <= 26*(n-i-1)) {
                    break;    
                }
            }
            res += ('a'+j-1);
            k -= j;
        }
        return res;
    }
};

//--- method 2: greedy backward
class Solution {
public:
    string getSmallestString(int n, int k) {
        string res(n, 'a');
        k -= n;
        for (int i = n-1; i >= 0; --i) {
            res[i] += min(25, k);
            k -= min(25, k);
        }
        return res;
    }
};