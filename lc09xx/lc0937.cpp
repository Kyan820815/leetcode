//--- Q: 0937. Reorder Data in Log Files

//--- method 1: only sort letter file
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<pair<string, string>> letters;
        vector<string> digits;
        for (auto &log: logs) {
            if (isdigit(log.back())) {
                digits.push_back(log);
            } else {
                string id = "";
                int i;
                for (i = 0; log[i] != ' '; ++i) {
                    id += log[i];
                }
                letters.push_back({id, log.substr(i+1)});
            }
        }
        sort(letters.begin(), letters.end(), [](const pair<string,string> &a, const pair<string,string> &b) {
            return a.second < b.second || a.second == b.second && a.first < b.first;
        });
        vector<string> res;
        for (auto &letter: letters) {
            res.push_back(letter.first + " " + letter.second);
        }
        res.insert(res.end(), digits.begin(), digits.end());
        return res;
    }
};