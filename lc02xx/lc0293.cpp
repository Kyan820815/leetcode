//--- Q: 0293. Flip Game

//--- method 1: string processing
class Solution {
public:
    vector<string> generatePossibleNextMoves(string currentState) {
        int n = currentState.size();
        vector<string> res;
        for (int i = 0; i < n-1; ++i) {
            if (currentState[i] == '+' && currentState[i+1] == '+') {
                auto tmp = currentState;
                tmp[i] = tmp[i+1] = '-';
                res.push_back(tmp);
            }
        }
        return res;
    }
};