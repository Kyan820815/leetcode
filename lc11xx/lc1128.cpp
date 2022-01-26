//--- Q: 1128. Number of Equivalent Domino Pairs

//--- method 1: two digit transformation
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int,int> map;
        int res = 0;
        for (auto &domino: dominoes) {
            int tag = domino[0] < domino[1] ? domino[0]*10+domino[1] : domino[1]*10+domino[0];
            res += map[tag]++;
        }
        return res;
    }
};

//--- method 2: bit operation hash
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int,int> map;
        int res = 0;
        for (auto &domino: dominoes) {
            int tag = (1 << domino[0]) | (1 << domino[1]);
            res += map[tag]++;
        }
        return res;
    }
};