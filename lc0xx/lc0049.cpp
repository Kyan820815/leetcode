//--- Q: 049. Group Anagrams

//--- method 1: map and O(n) conting sort
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        string id;
        unordered_map<string, int> map;
        unordered_map<string, int>::iterator iter;
        vector<vector<string>> output;
        int idx = 0;
        for (int i = 0; i < strs.size(); ++i)
        {
        	id.clear();
        	id.resize(26, '0');
        	for (int j = 0; j < strs[i].size(); ++j)
        		id[strs[i][j]-'a'] = (id[strs[i][j]-'a']-'0')+1+'0';
        	bool find = false;
			if ((iter = map.find(id)) == map.end())
			{
				map[id] = idx++;
				output.push_back({strs[i]});
			}
			else
				output[iter->second].push_back(strs[i]);
        }
        return output;
    }
};

//--- method 2: map and O(nlonn) sort
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> id;
        unordered_map<string, int>::iterator iter;
        vector<vector<string>> output;
        int idx = 0;
        for (int i = 0; i < strs.size(); ++i)
        {
        	string copy = strs[i];
        	sort(copy.begin(), copy.end());
        	if ((iter = id.find(copy)) == id.end())
        	{
				output.push_back({strs[i]});
				id[copy] = idx++;
        	}
        	else
        		output[iter->second].push_back(strs[i]);
        }
        return output;
    }
};