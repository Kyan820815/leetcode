//--- Q: 2085. Count Common Words With One Occurrence

//--- method 1: map operation
class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int> map;
        int res = 0;
        for (auto &word: words1) {
            ++map[word];
        }
        for (auto &word: words2) {
            if (map.find(word) != map.end()) {
                if (map[word] > 1) {
                    map.erase(word);
                } else {
                    --map[word];
                }
            }
        }
        for (auto &wd: map) {
            res += !wd.second;
        }
        return res;
    }
};