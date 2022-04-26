//--- Q: 1908. Game of Nim

//--- method 1: xor
class Solution {
public:
    bool nimGame(vector<int>& piles) {
        int res = 0;
        for (auto &pile: piles) {
            res ^= pile;
        }
        return res;
    }
};