//--- Q: 245. Shortest Word Distance III

//--- method 1: two pointer
class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int res = INT_MAX, last1 = -words.size(), last2 = -words.size();
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == word1 && words[i] == word2) {
                res = min(res, i-last1);
                last1 = i;                    
            } else if (words[i] == word1) {
                res = min(res, i - last2);
                last1 = i;
            } else if (words[i] == word2) {
                res = min(res, i - last1);
                last2 = i;
            }
        }
        return res;
    }
};