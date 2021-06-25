//--- Q: 1859. Sorting the Sentence

//--- method 1: sort sentence using pair
class Solution {
public:
    string sortSentence(string s) {
        vector<pair<char, string>> pool;
        string str = "", res = "";
        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) {
                pool.push_back({s[i], str});
                str = "";
                ++i;
            } else {
                str.push_back(s[i]);
            }
        }
        sort(pool.begin(), pool.end(), [](pair<char, string> &a, pair<char, string> &b){
            return a.first < b.first;
        });
        for (auto &wd: pool) {
            res += wd.second + " ";
        }
        res.pop_back();
        return res;
    }
};

//--- method 2: linear filling with index
class Solution {
public:
    string sortSentence(string s) {
        vector<string> pool(9);
        string str = "", res = "";
        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) {
                pool[s[i]-'1'] = str;
                str = "";
                ++i;
            } else {
                str.push_back(s[i]);
            }
        }
        for (auto &wd: pool) {
            if (!wd.size()) {
                break;
            }
            res += wd + " ";
        }
        res.pop_back();
        return res;
    }
};