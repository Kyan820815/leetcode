//--- Q: 1657. Determine if Two Strings Are Close

//--- method 1: sort
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> cnt1(26, 0), cnt2(26, 0);
        for (int i = 0; i < word1.size(); ++i) {
            ++cnt1[word1[i]-'a'];
        }
        for (int i = 0; i < word2.size(); ++i) {
            if (!cnt1[word2[i]-'a']) {
                return false;
            }
            ++cnt2[word2[i]-'a'];
        }
        sort(cnt1.begin(), cnt1.end());
        sort(cnt2.begin(), cnt2.end());
        return cnt1 == cnt2;
    }
};

//--- method 2: bucket sort
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> times1(100001, 0), times2(100001, 0);
        vector<int> cnt1(26, 0), cnt2(26, 0);
        for (int i = 0; i < word1.size(); ++i) {
            ++cnt1[word1[i]-'a'];
        }
        for (int i = 0; i < word2.size(); ++i) {
            if (!cnt1[word2[i]-'a']) {
                return false;
            }
            ++cnt2[word2[i]-'a'];
        }
        for (int i = 0; i < 26; ++i) {
            ++times1[cnt1[i]];
            ++times2[cnt2[i]];
        }
        return times1 == times2;
    }
};
