//--- Q: 0650. 2 Keys Keyboard

//--- method 2: recursion
class Solution {
public:
    int minSteps(int n) {
        for (int i = n-1; i >= 1; --i) {
            if (n%i == 0) {
                return n/i+minSteps(i);
            }
        }
        return 0;
    }
};

//--- method 2: dp iteration
class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n+1, 0);
        for (int i = 2; i <= n; ++i) {
            for (int j = i-1; j >= 1; --j) {
                if (i%j == 0) {
                    dp[i] = i/j+dp[j];
                    break;
                }
            }
        }
        return dp[n];
    }
};

//--- method 3: O(1) space iteration
class Solution {
public:
    int minSteps(int n) {
        int res = 0;
        while (n != 1) {
            for (int i = n-1; i >= 1; --i) {
                if (n%i == 0) {
                    res += n/i;
                    n = i;
                    break;
                }
            }
        }
        return res;
    }
};