//--- Q: 1170. Compare Strings by Frequency of the Smallest Character

//--- method 1: bucket sort
class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> map(11, 0), res;
        for (int i = 0; i < words.size(); ++i) {
            ++map[countf(words[i])];
        }
        int sum = 0;
        for (int i = 10; i >= 1; --i) {
            int tmp = map[i];
            map[i] = sum;
            sum += tmp;
        }
        for (int i = 0; i < queries.size(); ++i) {
            res.push_back(map[countf(queries[i])]);
        }
        return res;
    }
    int countf(string &word) {
        vector<int> cnt(26, 0);
        for (int j = 0; j < word.size(); ++j) {
            ++cnt[word[j]-'a'];
        }
        for (int j = 0; j < 26; ++j) {
            if (cnt[j]) {
                return cnt[j];
            }
        }
        return 0;
    }

};