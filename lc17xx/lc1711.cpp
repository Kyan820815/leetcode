//--- Q: 1711. Count Good Meals

//--- method 1: map
class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        int n = deliciousness.size(), res = 0, mod = 1e9+7;
        vector<int> pow(22, 0);
        pow[0] = 1;
        for (int i = 1; i < 22; ++i) {
            pow[i] = (pow[i-1] << 1);
        }
        unordered_map<int, int> map;
        for (auto &d: deliciousness) {
            for (auto &p: pow) {
                res = (res+map[p-d])%mod;
            }
            ++map[d];
        }
        return res;            
    }
};