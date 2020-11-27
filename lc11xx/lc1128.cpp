//--- Q: 1128. Number of Equivalent Domino Pairs

//--- method 1: bit operation hash
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> map;
        int res = 0;
        for (int i = 0; i < dominoes.size(); ++i) {
            int now = 1 << dominoes[i][0] | 1 << dominoes[i][1];
            if (map.find(now) != map.end())
                res += map[now];
            ++map[now];
        }
        return res;
    }
};
