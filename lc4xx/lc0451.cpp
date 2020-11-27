//--- Q: 451. Sort Characters By Frequency

//--- method 1: bucket sort
class Solution {
public:
    string frequencySort(string s) {
    	unordered_map<char,int> ch;
    	vector<string> times(s.size()+1, "");
    	string res = "";
        for (int i = 0; i < s.size(); ++i)
        	ch[s[i]]++;
        for (auto &c: ch)
        {
        	for (int i = 0; i < c.second; ++i)
            	times[c.second].push_back(c.first);
        }
        for (int i = times.size()-1; i >= 0; --i)
        {
            if (times[i].size() > 0)
                res += times[i];
        }
        return res;
    }
};

//--- method 2: O(nlogn)
class Solution {
public:
    string frequencySort(string s) {
    	unordered_map<char,int> ch;
    	vector<string> times(s.size()+1, "");
    	string res = "";
        for (int i = 0; i < s.size(); ++i)
        	ch[s[i]]++;

        sort(s.begin(), s.end(), [&ch](char a, char b)
        {
        	return ch[a] > ch[b] || ch[a] == ch[b] && a < b;	
        });

        return s;
    }
};