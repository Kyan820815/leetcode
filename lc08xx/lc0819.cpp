//--- Q: 0819. Most Common Word

//--- method 1: string operation
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        istringstream ss(paragraph);
        string str = "";
        map<string,int> map;
        unordered_set<string> ban_set(banned.begin(), banned.end());
        for (int i = 0; i <= paragraph.size(); ++i) {
            if (i == paragraph.size() || !isalpha(paragraph[i])) {
                if (str.size() && ban_set.find(str) == ban_set.end()) {
                    ++map[str];
                }
                str = "";
            } else {
                str.push_back(tolower(paragraph[i]));
            }
        }
        int res = 0;
        string resstr = "";
        for (auto &node: map) {
            if (node.second > res) {
                res = node.second;
                resstr = node.first;
            }
        }
        return resstr;
    }
};

//--- method 2: string operation with stringstream
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        map<string,int> map;
        unordered_set<string> ban_set(banned.begin(), banned.end());
        for (int i = 0; i < paragraph.size(); ++i) {
            paragraph[i] = isalpha(paragraph[i]) ? tolower(paragraph[i]) : ' ';
        }
        istringstream ss(paragraph);
        string word, resstr;
        int res = 0;
        while (ss >> word) {
            if (ban_set.find(word) != ban_set.end()) {
                continue;
            }
            if (++map[word] > res) {
                res = map[word];
                resstr = word;
            }
        }
        return resstr;
    }
};