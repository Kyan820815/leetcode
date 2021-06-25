//--- Q: 722. Remove Comments

//--- method 1: string operation
class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> res;
        int use_block = 0, block_line = -1;
        for (int i = 0; i < source.size(); ++i) {
            string res_line = "", &line = source[i];
            int last = 0, use_slash = 0, connect = 0;
            for (int j = 0; j <= line.size(); ++j) {
                if (j == line.size() && !use_block) {
                    res_line += line.substr(last, j-last);
                } else if (j+1 < line.size() && line[j] == '/' && line[j+1] == '/' && !use_block) {
                    res_line += line.substr(last, j-last);
                    use_slash = 1;
                    break;
                } else if (j+1 < line.size() && line[j] == '/' && line[j+1] == '*' && !use_block) {
                    use_block = 1;
                    block_line = i;
                    res_line += line.substr(last, j-last);
                    j += 1;
                } else if (line[j] == '*' && line[j+1] == '/' && use_block) {
                    use_block = 0;
                    if (!connect && block_line != i) {
                        connect = 1;
                    }
                    block_line = -1;
                    last = j+2;
                    j += 1;
                }
            }
            if (!use_block && !use_slash && !last) {
                res.push_back(line);
            } else if (res_line.size()) {
                if (res.size() && connect) {
                    res.back() += res_line;
                } else {
                    res.push_back(res_line);
                }
            }
        }
        return res;
    }
};