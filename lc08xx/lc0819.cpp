//--- Q: 819. Most Common Word

//--- method 1: string operation, clean code
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
    	string str, res = "";
    	int maxv = INT_MIN;
    	unordered_map<string, int> map;
    	for (int i = 0; i < banned.size(); ++i)
    		map[banned[i]] = -1;
    	for (int i = 0; i < paragraph.size(); ++i)
    		paragraph[i] = (isalpha(paragraph[i])) ? tolower(paragraph[i]) : ' ';
    	istringstream ss(paragraph);
    	while (ss >> str)
    	{
    		if (map[str] != -1)
    			++map[str];
    		if (map[str] > maxv)
    		{
    			maxv = map[str];
    			res = str;
    		}
    	}
    	return res;
    }
};

//--- method 2: string operation
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
    	string str;
    	int maxv = INT_MIN, idx = 0;
    	unordered_map<string, int> map;
    	for (int i = 0; i < banned.size(); ++i)
    		map[banned[i]] = -1;
    	while (idx < paragraph.size())
    	{
    		string now = "";
    		while (idx < paragraph.size() && ((paragraph[idx] >= 'a' && paragraph[idx] <= 'z') 
    			                           || (paragraph[idx] >= 'A' && paragraph[idx] <= 'Z')))
    		{
    			if (paragraph[idx] >= 'A' && paragraph[idx] <= 'Z')
    				paragraph[idx] ^= 32;
    			now.push_back(paragraph[idx++]);
    		}
    		if (now != "" && map[now] != -1)
    			++map[now];
    		++idx;
    	}
    	for (auto &m: map)
    	{
    		if (m.second > maxv)
    		{
    			maxv = m.second;
    			str = m.first;
    		}
    	}
    	return str;
    }
};