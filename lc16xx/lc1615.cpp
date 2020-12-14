//--- Q: 1615. Maximal Network Rank

//--- method 1: set
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int res = 0;
        vector<unordered_set<int>> rel(n);
        for (int i = 0; i < roads.size(); ++i) {
            rel[roads[i][0]].insert(roads[i][1]);
            rel[roads[i][1]].insert(roads[i][0]);
        }
        for (int i = 0; i < n-1; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (rel[i].find(j) != rel[i].end()) {
                    res = max(res, (int)rel[i].size()+(int)rel[j].size()-1);
                } else {
                    res = max(res, (int)rel[i].size()+(int)rel[j].size());
                }
            }
        }
        return res;
    }
};

//--- follow up: O(n)
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int res = 0;
        vector<unordered_set<int>> rel(n);
        for (int i = 0; i < roads.size(); ++i) {
            rel[roads[i][0]].insert(roads[i][1]);
            rel[roads[i][1]].insert(roads[i][0]);
        }
        int maxv = 0, maxcnt = 0, maxid;
        for (int i = 0; i < n; ++i) {
        	if (maxv < rel[i].size()) {
        		maxv = rel[i].size();
                maxid = i;
                maxcnt = 1;
        	} else if (maxv == rel[i].size()) {
        		++maxcnt;
        	}
        }
        if (maxcnt == 1) {
        	for (int i = 0; i < n; ++i) {
        		if (i != maxid) {
        			res = max(res, maxv + (int)rel[i].size() + (rel[i].find(maxid) == rel[i].end() ? 0 : -1));
        		}
        	}
        } else {
        	int edge = 0;
        	for (int i = 0; i < roads.size(); ++i) {
        		if (rel[roads[i][0]].size() == maxv && rel[roads[i][1]].size() == maxv) {
        			++edge;
        		}
        	}
        	res = maxv*2 + ((maxcnt * (maxcnt - 1))/2 > edge ? 0 : -1);
        }
        return res;
    }
};
