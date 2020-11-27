//--- Q: 455. Assign Cookies

//--- method 1: nlog n sort, double pointer
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int res = 0;
        for (int i = 0, si = 0; i < g.size() && si < s.size(); ++si) {
            if (g[i] <= s[si]) {
                ++res;
                ++i;
            }
        }
        return res;
    }
};