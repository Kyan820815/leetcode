//--- Q: 1202. Smallest String With Swaps

//--- method 1: union find with path compression
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        vector<vector<int>> setc(n);
        vector<int> parent(n, -1);
        for (int i = 0; i < pairs.size(); ++i) {
            int ap = findP(pairs[i][0], parent);
            int bp = findP(pairs[i][1], parent);
             if (ap != bp) {
             	// store union size, make small group point to large group
                if (-parent[ap] < -parent[bp]) swap(ap, bp);
                // add small group to large group
                parent[ap] += parent[bp];
                // small group point to large group
                parent[bp] = ap;
            }
        }
        for (int i = 0; i < n; ++i) {
            int p = findP(i, parent);
            setc[p].push_back(i);
        }
        for (int i = 0; i < setc.size(); ++i) {
            vector<int> now = setc[i];
            string tmp = "";
            for (int j = 0; j < now.size(); ++j) {
                tmp.push_back(s[now[j]]);
            }
            sort(tmp.begin(), tmp.end());
            for (int j = 0; j < now.size(); ++j) {
                s[now[j]] = tmp[j];
            }
        }
        return s;
    }
    int findP(int i, vector<int>& parent) {
    	// path compression
        return parent[i] < 0 ? i : parent[i] = findP(parent[i], parent);
    }
};
