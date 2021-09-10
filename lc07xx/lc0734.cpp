//--- Q: 0734. Sentence Similarity

//--- method 1: union find without transition
class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        int i, j;
        unordered_map<string,unordered_set<string>> map;
        for (auto &pair: similarPairs) {
            map[pair[0]].insert(pair[1]);
        }
        for (i = 0, j = 0; i < sentence1.size() && j < sentence2.size(); ++i, ++j) {
            if (sentence1[i] != sentence2[j] 
                && map[sentence1[i]].find(sentence2[j]) == map[sentence1[i]].end()
                && map[sentence2[j]].find(sentence1[i]) == map[sentence2[j]].end()) {
                return false;
            }
        }
        return sentence1.size() == sentence2.size();
    }
};

//--- method 2: unordered_set
class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        int i, j;
        unordered_set<string> set;
        for (auto &pair: similarPairs) {
            set.insert(pair[0]+" "+pair[1]);
        }
        for (i = 0, j = 0; i < sentence1.size() && j < sentence2.size(); ++i, ++j) {
            if (sentence1[i] != sentence2[j] 
                && set.find(sentence1[i]+" "+sentence2[j]) == set.end()
                && set.find(sentence2[j]+" "+sentence1[i]) == set.end()) {
                return false;
            }
        }
        return sentence1.size() == sentence2.size();
    }
};