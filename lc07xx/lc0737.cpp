//--- Q: 0737. Sentence Similarity II

//--- method 1: union find
class Solution {
public:
    unordered_map<string, string> parent;
    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        for (auto &pair: similarPairs) {
            auto ap = findp(pair[0]);
            auto bp = findp(pair[1]);
            if (ap != bp) {
                parent[ap] = bp;
            }
        }
        int i, j;
        for (i = 0, j = 0; i < sentence1.size() && j < sentence2.size(); ++i, ++j) {
            auto ap = findp(sentence1[i]);
            auto bp = findp(sentence2[j]);
            if (ap != bp) {
                return false;
            }
        }
        return i == sentence1.size() && j == sentence2.size();
    }
    string findp(string &now) {
        if (parent.find(now) == parent.end()) {
            return parent[now] = now;
        } else if (parent[now] == now) {
            return now;
        } else {
            return parent[now] = findp(parent[now]);
        }
    }
};