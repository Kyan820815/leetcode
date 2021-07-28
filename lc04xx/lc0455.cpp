//--- Q: 0455. Assign Cookies

//--- method 1: nlog n sort, double pointer
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i, j;
        for (i = 0, j = 0; i < g.size() && j < s.size(); ++j) {
            if (g[i] <= s[j]) {
                ++i;
            }
        }
        return i;
    }
};