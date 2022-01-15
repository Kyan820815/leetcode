//--- Q: 1049. Last Stone Weight II

//--- method 1: O(nm) time
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (auto &stone: stones) {
            sum += stone;
        }
        vector<int> dp(sum/2+1, 0);
        dp[0] = 1;
        for (auto &stone: stones) {
            auto tmp = dp;
            for (int i = stone; i <= sum/2; ++i) {
                tmp[i] |= dp[i-stone];
            }
            dp = tmp;
        }
        for (int i = sum/2; i > 0; --i) {
            if (dp[i]) {
                return sum-2*i;
            }
        }
        return sum;
    }
};

//--- method 2: O(n) time bit set
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (auto &stone: stones) {
            sum += stone;
        }
        bitset<1501> dp(1);
        for (auto &stone: stones) {
            dp |= (dp << stone);
        }
        for (int i = sum/2; i > 0; --i) {
            if (dp[i]) {
                return sum-2*i;
            }
        }
        return sum;
    }
};