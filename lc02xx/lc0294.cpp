//--- Q: 0294. Flip Game II

//--- method 1: dp
class Solution {
public:
    unordered_map<string, bool> dp;
    bool canWin(string currentState) {
        if (dp.find(currentState) != dp.end()) {
            return dp[currentState];
        }
        int n = currentState.size();
        for (int i = 0; i < n-1; ++i) {
            if (currentState[i] == '+' && currentState[i+1] == '+') {
                currentState[i] = currentState[i+1] = '-';
                auto nstate = canWin(currentState);
                currentState[i] = currentState[i+1] = '+';
                if (!nstate) {
                    return dp[currentState] = true;
                }
            }
        }
        return dp[currentState] = false;
    }
};