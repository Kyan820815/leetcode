//--- Q: 937. Reorder Data in Log Files

//--- method 1: only sort letter file
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> res, digitfile;
        vector<pair<string, string>> letterfile;
        auto comp = [](pair<string, string> &a, pair<string, string> &b) {
            return a.second < b.second || a.second == b.second && a.first < b.first;
        };
        for (int i = 0; i < logs.size(); ++i) {
            int j;
            for (j = 0; logs[i][j] != ' '; ++j);
            if (isalpha(logs[i][j+1]))
                letterfile.push_back({logs[i].substr(0, j), logs[i].substr(j+1)});
            else
                digitfile.push_back(logs[i]);
        }
        sort(letterfile.begin(), letterfile.end(), comp);
        for (int i = 0; i < letterfile.size(); ++i)
            res.push_back(letterfile[i].first + " " + letterfile[i].second);
        res.insert(res.end(), digitfile.begin(), digitfile.end());
        return res;
    }
};