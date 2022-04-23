//--- Q: 1554. Strings Differ by One Character

//--- method 1: rolling hash
class Solution {
public:
    using ll = long long;
    bool differByOne(vector<string>& dict) {
        int n = dict.size(), m = dict[0].size();
        int mod = 1e9+7;
        vector<int> hash(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                hash[i] = ((ll)hash[i]*26 + (dict[i][j]-'a'))%mod;
            }
        }
        for (int j = m-1, mul = 1; j >= 0; --j) {
            unordered_map<int, vector<int>> map;
            for (int i = 0; i < n; ++i) {
                int hval = (hash[i]-(ll)mul*(dict[i][j]-'a')%mod+mod)%mod;
                auto it = map.find(hval);
                if (it != map.end()) {
                    for (auto &k: it->second) {
                        if (dict[k].substr(0,j) == dict[i].substr(0,j) && dict[k].substr(j+1) == dict[i].substr(j+1)) {
                            return true;
                        }
                    }
                }
                map[hval].push_back(i);
            }
            mul = ((ll)mul*26)%mod;
        }
        return false;
    }
};
