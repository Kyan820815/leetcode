//--- Q: 0392. Is Subsequence

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
        vector<vector<int>> map(t.size(), vector<int>(26, t.size()));
        for (int i = t.size()-1; i >= 0; --i) {
            map[i][t[i]-'a'] = i;
            if (i > 0) {
                map[i-1] = map[i];
            }
        }
        int i, j;
        for (i = 0, j = 0; i < s.size(); ++i) {
            if (j == t.size() || map[j][s[i]-'a'] == t.size()) {
                return false;
            }
            j = map[j][s[i]-'a']+1;
        }
        return i == s.size();
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
            auto vec = list[t[i]-'a'];
            list[t[i]-'a'].clear();
            for (auto &j: vec) {
                if (j+1 == s.size()) {
                    return true;
                }
                list[s[j+1]-'a'].push_back(j+1);
            }
        }
        return false;
    }
};