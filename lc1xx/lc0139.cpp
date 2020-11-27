//--- Q: 139. Word Break

//--- method1: dp iteration
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
    	
        vector<int> dp(s.size(),0);
        findWord(s, wordDict, dp);
        return dp[s.size()-1];
    }
    void findWord(string s, vector<string> wordDict, vector<int> &dp)
    {
    	int idx;

        for (int i = 0; i < dp.size(); ++i)
        {
            for (int j = i; j >= 0; --j)
            {
                if ((j==0 || dp[j-1]) && find(wordDict.begin(), wordDict.end(), s.substr(j, i-j+1)) != wordDict.end())
                {
                    dp[i] = 1;
                    break;
                }
            }
        }
    }
};

//--- method 2: dp recursion
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        bool res = false;
        if (map.count(s)) return map[s];
        if (s == "") return true;
        for (int i = 0; i < wordDict.size(); ++i)
        {
            if (s.substr(0, wordDict[i].size()) != wordDict[i])
                continue;
            bool get = wordBreak(s.substr(wordDict[i].size()), wordDict);
            res |= get;
        }
        return map[s] = res;
    }
private:
    unordered_map<string, bool> map;
};