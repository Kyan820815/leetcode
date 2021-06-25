//--- Q: 243. Shortest Word Distance

//--- method 1: one pass, double pointer
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int last1 = -words.size(), last2 = -words.size(), res = INT_MAX;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == word1) {
                res = min(res, i-last2);
                last1 = i;
            } else if (words[i] == word2) {
                res = min(res, i-last1);
                last2 = i;
            }
        }
        return res;
    }
};