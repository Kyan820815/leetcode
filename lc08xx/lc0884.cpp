//--- Q: 0884. Uncommon Words from Two Sentences

//--- method 1: find the word appearing once
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> res;
        string word = "";
        unordered_map<string, int> map;
        for (int i = 0; i <= s1.size(); ++i) {
            if (i == s1.size() || s1[i] == ' ') {
                ++map[word];
                word = "";
            } else {
                word += s1[i];
            }
        }
        for (int i = 0; i <= s2.size(); ++i) {
            if (i == s2.size() || s2[i] == ' ') {
                ++map[word];
                word = "";
            } else {
                word += s2[i];
            }
        }
        for (auto &word: map) {
            if (word.second == 1) {
                res.push_back(word.first);
            }
        }
        return res;
    }
};

//--- method 2: istringstream parser
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> res;
        istringstream ss(s1);
        unordered_map<string, int> map;
        string str;
        while (ss >> str) {
            ++map[str];
        }
        ss.clear();
        ss.str(s2);
        while (ss >> str) {
            ++map[str];
        }
        for (auto &str: map) {
            if (str.second == 1) {
                res.push_back(str.first);
            }
        }
        return res;
    }
};