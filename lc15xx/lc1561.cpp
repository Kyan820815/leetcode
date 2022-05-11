//--- Q: 1561. Maximum Number of Coins You Can Get

//--- method 1: sort and greedy
`class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int n = piles.size()/3, res = 0;
        for (int i = n; i < 3*n; i+=2) {
            res += piles[i];
        }
        return res;
    }
};