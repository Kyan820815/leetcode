//--- Q:734. Sentence Similarity

//--- method 1: union find without transition
class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if (words1.size() != words2.size())
            return false;
        unordered_map<string, unordered_set<string>> set;
        for (int i = 0; i < pairs.size(); ++i) {
            set[pairs[i][0]].insert(pairs[i][1]);
        }
        for (int i = 0; i < words1.size(); ++i) {
            if (words1[i] == words2[i] || set[words1[i]].find(words2[i]) != set[words1[i]].end()
                                       || set[words2[i]].find(words1[i]) != set[words2[i]].end())
                continue;
            return false;
        }
        return true;
    }
};

//--- method 2: unordered_set
class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if (sentence1.size() != sentence2.size()) {
            return false;
        }
        unordered_set<string> set;
        for (int i = 0; i < similarPairs.size(); ++i) {
            set.insert(similarPairs[i][0] + " " + similarPairs[i][1]);
            set.insert(similarPairs[i][1] + " " + similarPairs[i][0]);
        }
        for (int i = 0; i < sentence1.size(); ++i) {
            if (sentence1[i] == sentence2[i]) {
                continue;
            }
            string str = sentence1[i] + " " + sentence2[i];
            if (set.find(str) == set.end()) {
                return false;
            }
        }
        return true;
    }
};