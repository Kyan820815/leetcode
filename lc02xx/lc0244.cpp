//--- Q: 244. Shortest Word Distance II

//--- method 1: hash map and double pointer
class WordDistance {
public:
    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i)
            map[words[i]].push_back(i);
    }
    
    int shortest(string word1, string word2) {
        int l = 0, r = 0, res = INT_MAX;
        vector<int> left = map[word1], right = map[word2];
        while (l < left.size() && r < right.size()) {
            if (left[l] < right[r]) {
                res = min(res, right[r] - left[l]);
                ++l;
            } else {
                res = min(res, left[l] - right[r]);
                ++r;
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
