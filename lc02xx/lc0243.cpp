//--- Q: 0243. Shortest Word Distance

//--- method 1: one pass, double pointer
class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int n = wordsDict.size(), last1 = -n, last2 = -n, res = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (wordsDict[i] == word1) {
                res = min(res, i-last2);
                last1 = i;
            } else if (wordsDict[i] == word2) {
                res = min(res, i-last1);
                last2 = i;
            }
        }
        return res;
    }
};