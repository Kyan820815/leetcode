//--- Q: 140. Word Break II

//--- method 1: dp recursion
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
    	vector<string> res;
    	if (map.count(s)) return map[s];
    	if (s == "") return {""};
    	for (int i = 0; i < wordDict.size(); ++i)
    	{
    		if (s.substr(0, wordDict[i].size()) != wordDict[i])
    			continue;
    		vector<string> recur = wordBreak(s.substr(wordDict[i].size()), wordDict);
    		for (int j = 0; j < recur.size(); ++j)
    		{
    			res.push_back(wordDict[i] + ((recur[j] == "") ? "" : " ")  + recur[j]);
    		}
    	}
    	return map[s] = res;
    }
private:
	unordered_map<string, vector<string>> map;
};

//--- method 2: dp recurtion without memorization
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        return dfs(s, set);
    }
    vector<string> dfs(string &s, unordered_set<string> &set) {
        if (!s.size()) {
            return {""};
        }
        string tmp = "";
        vector<string> res;
        for (int i = 0; i < s.size(); ++i) {
            tmp += s[i];
            if (set.find(tmp) == set.end()) {
                continue;
            }
            string next = s.substr(i+1);
            auto vec = dfs(next, set);
            for (int i = 0; i < vec.size(); ++i) {
                res.push_back(tmp + (!vec[i].size() ? "" : " ") + vec[i]);
            }
        }
        return res;
    }
};