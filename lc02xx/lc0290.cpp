//--- Q: 290. Word Pattern

//--- method 1: double hashmap to record 1 to 1 relation
class Solution {
public:
    bool wordPattern(string pattern, string str) {
    	unordered_map<string, char> foward;
    	unordered_map<char, string> back;
        istringstream ss(str);
        string word;
        int idx = 0;
        while (ss >> word)
        {
            if (!foward.count(word))
        	{
        		foward[word] = pattern[idx];
        		if (back.count(pattern[idx])) return false;
        		else
        			back[pattern[idx]] = word;
        	}
        	else if (foward[word] != pattern[idx] || back[pattern[idx]] != word)
        		return false;
        	++idx;
        }
        return idx == pattern.size() ? true : false;
    }
};