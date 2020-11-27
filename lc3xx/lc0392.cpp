//--- Q: 392. Is Subsequence

//--- method 1: two pointer O(n) space
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int left = 0, right = 0;
        while (left < s.size() && right < t.size())
        {
        	if (s[left] == t[right])
        		++left;
        	++right;
        }
        return left == s.size() ? true : false;
    }
};

//--- follow up:
class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> cnt(t.size(), vector<int>(26, t.size()));
        for (int i = t.size()-1; i >= 0; --i) {
            if (i < t.size()-1) {
                cnt[i] = cnt[i+1];
            }
            cnt[i][t[i]-'a'] = i;
        }
        int index = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (index == t.size() || cnt[index][s[i]-'a'] == t.size()) {
                return false;
            }
            index = cnt[index][s[i]-'a']+1;
        }
        return true;
    }
};