//--- Q: 500. Keyboard Row

//--- method 1: 
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<unordered_set<char>> set(3);
        vector<string> res;
        set[0] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
        set[1] = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
        set[2] = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};
        for (int i = 0; i < words.size(); ++i) {
            int type;
            for (int j = 0; j < 3; ++j) {
                if (set[j].find(words[i][0]) != set[j].end() || set[j].find(words[i][0]^32) != set[j].end()) {
                    type = j;
                    break;
                }
            }
            bool find = true;
            for (int j = 1; j < words[i].size(); ++j) {
                if (set[type].find(words[i][j]) == set[type].end() && set[type].find(words[i][j]^32) == set[type].end()) {
                    find = false;
                    break;
                }
            }
            if (find) {
                res.push_back(words[i]);
            }
        }
        return res;
    }
};