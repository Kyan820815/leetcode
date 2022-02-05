//--- Q: 2114. Maximum Number of Words Found in Sentences

//--- method 1: linear processing
class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int res = 0;
        for (auto &sentence: sentences) {
            int word = 0;
            for (int i = 0; i <= sentence.size(); ++i) {
                word += i == sentence.size() || sentence[i] == ' ';
            }
            res = max(res, word);
        }
        return res;
    }
};