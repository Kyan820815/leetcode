//--- Q: 0244. Shortest Word Distance II

//--- method 1: hash map and double pointer
class WordDistance {
public:
    WordDistance(vector<string>& wordsDict) {
        for (int i = 0; i < wordsDict.size(); ++i) {
            map[wordsDict[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int i = 0, j = 0;
        auto &vec1 = map[word1];
        auto &vec2 = map[word2];
        int res = INT_MAX;
        while (i < vec1.size() && j < vec2.size()) {
            if (vec1[i] < vec2[j]) {
                res = min(res, vec2[j]-vec1[i]);
                ++i;
            } else {
                res = min(res, vec1[i]-vec2[j]);
                ++j;
            }
        }
        return res;
    }
    unordered_map<string, vector<int>> map;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */
