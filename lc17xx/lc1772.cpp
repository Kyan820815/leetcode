//--- Q: 1772. Sort Features by Popularity

//--- method 1: map and stable sort
class Solution {
public:
    vector<string> sortFeatures(vector<string>& features, vector<string>& responses) {
        unordered_map<string, int> cnt;
        for (auto &sentence: responses) {
            istringstream ss(sentence);
            string str;
            unordered_set<string> pool;
            while (ss >> str) {
                if (pool.find(str) == pool.end()) {
                    pool.insert(str);
                    ++cnt[str];
                }
            }
        }
        stable_sort(features.begin(), features.end(), [&cnt](const string &a, const string &b) {
            return cnt[a] > cnt[b];
        });
        return features;
    }
};