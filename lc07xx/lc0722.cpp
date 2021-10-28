//--- Q: 0722. Remove Comments

//--- method 1: string operation
class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> res;
        int use_block = 0, start_line = -1;
        for (int i = 0; i < source.size(); ++i) {
            string res_line = "";
            int last = 0, same_line = 0;
            for (int j = 0; j < source[i].size(); ++j) {
                if (!use_block && j+1 < source[i].size() && source[i][j] == '/' && source[i][j+1] == '/') {
                    res_line += source[i].substr(last, j-last);
                    last = source[i].size();
                    break;
                } else if (!use_block && j+1 < source[i].size() && source[i][j] == '/' && source[i][j+1] == '*') {
                    res_line += source[i].substr(last, j-last);
                    ++j;
                    start_line = i;
                    use_block = 1;
                } else if (use_block && j+1 < source[i].size() && source[i][j] == '*' && source[i][j+1] == '/') {
                    ++j;
                    last = j+1;
                    same_line |= (i != start_line);
                    use_block = 0;
                }
            }
            if (!use_block && last < source[i].size()) {
                res_line += source[i].substr(last, source[i].size()-last);
            }
            if (res_line.size()) {
                if (same_line && res.size()) {
                    res.back() += res_line;
                } else {
                    res.push_back(res_line);
                }
            }
        }
        return res;
    }
};