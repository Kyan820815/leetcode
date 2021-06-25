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

//--- follow up method 1:
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

//--- follow up method 2:
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (!s.size()) {
            return true;
        }
        vector<vector<int>> list(26);
        list[s[0]-'a'].push_back(0);
        for (int i = 0; i < t.size(); ++i) {
            vector<int> tmp = list[t[i]-'a'];
            list[t[i]-'a'].clear();
            for (int j = 0; j < tmp.size(); ++j) {
                if (tmp[j]+1 == s.size()) {
                    return true;
                } else {
                    list[s[tmp[j]+1]-'a'].push_back(tmp[j]+1);
                }
            }
        }
        return false;
    }
};