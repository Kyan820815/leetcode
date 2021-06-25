//--- Q: 771. Jewels and Stones

//--- method 1: O(1) space, bucket sort
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        vector<int> cnt(128, 0);
        for (int i = 0; i < jewels.size(); ++i) {
            ++cnt[jewels[i]];
        }
        int res = 0;
        for (int i = 0; i < stones.size(); ++i) {
            res += (cnt[stones[i]] == 1);
        }
        return res;
    }
};