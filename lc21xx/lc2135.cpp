//--- Q: 2135. Count Words Obtained After Adding a Letter

//--- method 1: sort
class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<string> set;
        for (auto &word: startWords) {
            sort(word.begin(), word.end());
            set.insert(word);
        }
        int res = 0;
        for (auto &word: targetWords) {
            sort(word.begin(), word.end());
            for (int i = 0; i < word.size(); ++i) {
                string tmp = word.substr(0,i) + word.substr(i+1);
                if (set.find(tmp) != set.end()) {
                    ++res;
                    break;
                }
            }
        }
        return res;
    }
};

//--- method 2: bit manipulation
class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<int> set;
        for (auto &word: startWords) {
            int val = 0;
            for (auto &ch: word) {
                val |= (1 << (ch-'a'));
            }
            set.insert(val);
        }
        int res = 0;
        for (auto &word: targetWords) {
            int val = 0;
            for (auto &ch: word) {
                val |= (1 << (ch-'a'));
            }
            for (auto &ch: word) {
                int tmp = val ^ (1 << (ch-'a'));
                if (set.find(tmp) != set.end()) {
                    ++res;
                    break;
                }
            }
        }
        return res;
    }
};