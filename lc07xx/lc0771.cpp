//--- Q: 0771. Jewels and Stones

//--- method 1: O(1) space, bucket sort
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int res = 0;
        vector<int> cnt(128, 0);
        for (auto &ch: jewels) {
            ++cnt[ch];
        }
        for (auto &ch: stones) {
            res += cnt[ch] > 0;
        }
        return res;
    }
};