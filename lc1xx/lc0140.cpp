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